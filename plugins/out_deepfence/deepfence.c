#include "toae.h"
#include "out_toae.h"

static int cb_toae_init(
	struct flb_output_instance *ins,
	struct flb_config *config,
	void *data)
{
    struct flb_toae *ctx = flb_calloc(1, sizeof(struct flb_toae));
    if (!ctx) {
        flb_errno();
        return -1;
    }
    ctx->ins = ins;

    int ret = flb_output_config_map_set(ins, (void *) ctx);
    if (ret == -1) {
        flb_free(ctx);
        return -1;
    }

	FLBPluginInit(
		(char*)flb_output_get_property("id", ins),
		(char*)flb_output_get_property("console_host", ins),
		(char*)flb_output_get_property("console_port", ins),
		(char*)flb_output_get_property("path", ins),
		(char*)flb_output_get_property("schema", ins),
		(char*)flb_output_get_property("token", ins),
		(char*)flb_output_get_property("cert_file", ins),
		(char*)flb_output_get_property("key_file", ins)
	);

    /* Export context */
    flb_output_set_context(ins, ctx);

    return 0;
}

static void cb_toae_flush(
	struct flb_event_chunk *event_chunk,
	struct flb_output_flush *out_flush,
	struct flb_input_instance *i_ins,
	void *out_context,
	struct flb_config *config)
{
    struct flb_toae *ctx = (struct flb_toae *) out_context;

	int ret = FLBPluginFlushCtx(
		(char*)flb_output_get_property("id", ctx->ins),
		event_chunk->data,
		event_chunk->size);

    FLB_OUTPUT_RETURN(ret);
}

static int cb_toae_exit(void *data, struct flb_config *config)
{
    struct flb_toae *ctx = data;

    if (!ctx) {
        return 0;
    }

    flb_free(ctx);
    return 0;
}

/* Configuration properties map */
static struct flb_config_map config_map[] = {
    {
     FLB_CONFIG_MAP_STR, "id", NULL,
     0, FLB_FALSE, 0,
     "Unique Id config"
    },
    {
     FLB_CONFIG_MAP_STR, "schema", NULL,
     0, FLB_FALSE, 0,
     "Schema used for accessing console URL"
    },
    {
     FLB_CONFIG_MAP_STR, "console_host", NULL,
     0, FLB_FALSE, 0,
     "Host URL"
    },
    {
     FLB_CONFIG_MAP_STR, "console_port", NULL,
     0, FLB_FALSE, 0,
     "Port URL"
    },
    {
     FLB_CONFIG_MAP_STR, "path", NULL,
     0, FLB_FALSE, 0,
     "Path to listen"
    },
    {
     FLB_CONFIG_MAP_STR, "token", NULL,
     0, FLB_FALSE, 0,
     "API token from console"
    },
    /* EOF */
    {0}
};

/* Plugin registration */
struct flb_output_plugin out_toae_plugin = {
    .name         = "toae",
    .description  = "Plugin sending data to toae server",
    .cb_init      = cb_toae_init,
    .cb_flush     = cb_toae_flush,
    .cb_exit      = cb_toae_exit,
    .flags        = 0,
    .workers      = 1,
    .event_type   = FLB_OUTPUT_LOGS | FLB_OUTPUT_METRICS | FLB_OUTPUT_TRACES,
    .config_map   = config_map
};
