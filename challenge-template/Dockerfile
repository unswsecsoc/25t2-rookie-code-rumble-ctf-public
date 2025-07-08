# Sample Dockerfile configuration for a binary challenge, change as needed.
# See https://docs.docker.com/engine/reference/builder/ for more.

# The `FROM` directive specifies which base image to pull from.
# I'm using Alpine Linux here because it's small (~5MB).
FROM alpine:latest

# The `WORKDIR` directive specifies where the working directory inside the
# image will be for subsequent directives.
WORKDIR /app

# The `COPY` directive copies every path except the last from the host
# filesystem into the last path specified on the container filesystem.
# The directive below copies `challenge.c` from the `src` folder on my computer
# into `.` on the container, which is `/app` since we changed our working
# directory earlier.
COPY src/challenge.c .

# The `RUN` directive specifies commands to be run during container
# construction. If multiple `RUN` directives exist in one Dockerfile, they are
# executed sequentially in-order. This can be useful if more complex setup is
# required.

# In this case, `apk` is the package manager for Alpine.
# Since I'll be running a native executable, I'm asking it to install `gcc`
# (the compiler) and `musl-dev` (the default C library for Alpine). If you
# already have prebuilt artefacts, you probably don't need the compiler.
RUN apk add coreutils socat gcc musl-dev

# Then, I compile the challenge source code. By default, the name of the
# executable is `a.out`.
RUN cc challenge.c

# The `EXPOSE` directive informs Docker and anyone reading the Dockerfile
# which ports this container intends to use. Best to leave this as 9999 so
# the Projects team can play around with it.
EXPOSE 9999

# The `CMD` directive specifies a command to be run when the container starts.
# Since I want people that connect to this container to interact with a binary,
# I'll tell `socat` to fork itself after receiving a connection on port 9999
# and run the executable compiled earlier. See the man pages on socat for more.

# TODO: Figure out how to redirect stderr to stdout.
CMD socat -d -d TCP-LISTEN:9999,fork SYSTEM:"stdbuf -i0 -o0 -e0 ./a.out"
