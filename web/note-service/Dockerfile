FROM python:3.13-bookworm
WORKDIR /a/very/strange/working/directory
COPY src .

RUN adduser --system --no-create-home jacobi

RUN apt update && \
    apt install coreutils && \
    pip install --no-cache-dir Flask && \
    chown jacobi /a/very/strange/working/directory && \
    cp /proc/sys/kernel/random/boot_id bootid
EXPOSE 9999

USER "jacobi"

CMD ["sh", "-c", "python server.py --boot_id_file ./bootid"]