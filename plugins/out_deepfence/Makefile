FLUENT_BIT?=/opt/fluent-bit/bin/fluent-bit

all: out_toae.a

toae.o: toae.c out_toae.h
	gcc  -I ../../lib/msgpack-c/include -I ../../lib/mpack-amalgamation-1.1/src -I ../../lib/ctraces/include -I ../../lib/cfl/lib/xxhash -I ../../lib/cfl/include/ -I ../../lib/cmetrics/include/ -I ../../lib/c-ares-1.19.0/include/ -I ../../lib/flb_libco/ -I ../../build/lib/monkey/include/monkey -I ../../lib/monkey/include -I ../../include -c toae.c -o toae.o

vendor:
	go mod tidy -v
	go mod vendor

out_toae.h: vendor out_toae.go
	go build -buildmode=c-archive -o out_toae.a out_toae.go

out_toae.a: toae.o
	ar r out_toae.a toae.o

clean:
	-rm ./*.so
	-rm ./*.a
	-rm ./*.o
	-rm out_toae.h
	-rm -rf ./vendor

docker:
	docker build -t fluentbit:toae .

run: all
	$(FLUENT_BIT) -c local-fluent-bit.conf
