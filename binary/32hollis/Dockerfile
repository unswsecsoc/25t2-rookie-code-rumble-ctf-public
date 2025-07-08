FROM rust:alpine

WORKDIR /app
# production.s is the same as challenge.s except with the real flag
COPY src/chal-prod.s .

RUN apk add coreutils socat git gcc musl-dev

# build mipsy
RUN git clone https://github.com/insou22/mipsy.git && \
    cd mipsy && \
    # cargo update updates dependencies to correct version of Rust
    cargo update && \
    cargo build --release && \
    cp target/release/mipsy /usr/local/bin/

EXPOSE 9999

# socat allows a command to communicate over a port
CMD socat -d -d TCP-LISTEN:9999,fork SYSTEM:"stdbuf -i0 -o0 -e0 mipsy ./chal-prod.s"
