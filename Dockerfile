FROM timothyliuxf/bgp_platform_base AS builder

WORKDIR /build
COPY . .
RUN autoreconf -i && ./configure && make -j$(nproc)

FROM timothyliuxf/bgp_platform_base AS runner

WORKDIR /app

COPY --from=builder /build/build ./build
COPY --from=builder /build/third_party/inotify-cpp/build/src/*.so* ./third_party/inotify-cpp/build/src/

ENTRYPOINT ./build/bin/bgp_platform