from flask import Flask, render_template, request, flash
from base64 import b64encode
from werkzeug.debug import get_machine_id, get_pin_and_cookie_name, DebuggedApplication
import os

app = Flask(__name__)
app.config["SECRET_KEY"] = "iasjdiasjndasindasndhoq08ihd983h8e9dhoS*(DOhsoduasoidjOI@ejoi)"

uploaded_files = set()

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        print(request.files)
        note_content = request.files["note"].stream.read()
        note_title = b64encode(note_content[:50]).decode()
        uploaded_files.add(note_title)
        flash("Your file has been successfully uploaded!", "success")
        if os.path.exists(note_title):
            flash(f"The file {note_title} already exists!", "danger")
        else:
            open(note_title, "wb").write(note_content)
            flash(f"Your file has been written to! It has been saved with the title: {note_title}", "success")

    return render_template("index.html")

@app.route("/file", methods=["POST"])
def files():
    note_title = request.form.get("title", "")
    if note_title not in uploaded_files:
        flash("This file has not been uploaded yet!", "danger")
        file_content = ""
    else:
        file_content = open(note_title).read()
    return render_template("file.html", note_title=note_title, note_content=file_content)


class FakeDebuggedApplication(DebuggedApplication):
    def pin_auth(self, request):
        self._failed_pin_auth.value = 0
        return super().pin_auth(request)

app.wsgi_app = FakeDebuggedApplication(app.wsgi_app, evalex=True)
app.wsgi_app.trusted_hosts.append("127.0.0.1")

if __name__ == "__main__":
    app.run("0.0.0.0", 9999, use_reloader=True)