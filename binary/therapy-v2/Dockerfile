FROM ubuntu:22.04

WORKDIR /app

RUN apt update && apt install -y \
    gcc \
    socat \
    coreutils \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

COPY src/chall.c .
COPY src/flag .

RUN gcc -o chall chall.c \
    -fno-stack-protector

EXPOSE 9999

CMD ["socat", "TCP-LISTEN:9999,reuseaddr,fork", "EXEC:stdbuf -i0 -o0 -e0 ./chall,stderr"]
