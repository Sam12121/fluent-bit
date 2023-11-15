module github.com/toae/ThreatMapper/toae_agent/tools/apache/fluentbit/out_toae

go 1.20

replace github.com/toae/golang_toae_sdk/client => ../../../../../golang_toae_sdk/client

replace github.com/toae/golang_toae_sdk/utils => ../../../../../golang_toae_sdk/utils

replace github.com/toae/ThreatMapper/toae_utils => ../../../../../toae_utils

require (
	github.com/toae/ThreatMapper/toae_utils v0.0.0-00010101000000-000000000000
	github.com/toae/golang_toae_sdk/client v0.0.0-00010101000000-000000000000
	github.com/toae/golang_toae_sdk/utils v0.0.0-00010101000000-000000000000
	github.com/fluent/fluent-bit-go v0.0.0-20230515084116-b93d969da46d
	github.com/hashicorp/go-retryablehttp v0.7.4
)

require (
	github.com/cenkalti/backoff/v4 v4.2.1 // indirect
	github.com/decred/dcrd/dcrec/secp256k1/v4 v4.2.0 // indirect
	github.com/goccy/go-json v0.10.2 // indirect
	github.com/google/uuid v1.3.1 // indirect
	github.com/hashicorp/go-cleanhttp v0.5.2 // indirect
	github.com/klauspost/compress v1.16.7 // indirect
	github.com/lestrrat-go/blackmagic v1.0.1 // indirect
	github.com/lestrrat-go/httpcc v1.0.1 // indirect
	github.com/lestrrat-go/httprc v1.0.4 // indirect
	github.com/lestrrat-go/iter v1.0.2 // indirect
	github.com/lestrrat-go/jwx/v2 v2.0.12 // indirect
	github.com/lestrrat-go/option v1.0.1 // indirect
	github.com/mattn/go-colorable v0.1.12 // indirect
	github.com/mattn/go-isatty v0.0.14 // indirect
	github.com/pierrec/lz4/v4 v4.1.18 // indirect
	github.com/rs/zerolog v1.30.0 // indirect
	github.com/segmentio/asm v1.2.0 // indirect
	github.com/twmb/franz-go v1.14.4 // indirect
	github.com/twmb/franz-go/pkg/kadm v1.9.0 // indirect
	github.com/twmb/franz-go/pkg/kmsg v1.6.1 // indirect
	github.com/ugorji/go/codec v1.1.7 // indirect
	golang.org/x/crypto v0.12.0 // indirect
	golang.org/x/sys v0.12.0 // indirect
)
