#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/clk.h>
#include <linux/io.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/pm_runtime.h>
#include <linux/console.h>
#include <linux/omap-dma.h>
#include <linux/platform_data/serial-omap.h>

#include "common.h"
#include "omap_hwmod.h"
#include "omap_device.h"
#include "omap-pm.h"
#include "soc.h"
#include "prm2xxx_3xxx.h"
#include "pm.h"
#include "cm2xxx_3xxx.h"
#include "prm-regbits-34xx.h"
#include "control.h"
#include "mux.h"
#include "serial-beagle.h"

static struct omap_device_pad beagle_uart3_pads[] __initdata = {
{
	.name = "uart3_cts_rctx.uart3_cts_rctx",
	.enable = OMAP_PIN_INPUT_PULLUP | OMAP_MUX_MODE0,
},
{
	.name = "uart3_rts_sd.uart3_rts_sd",
	.enable = OMAP_PIN_OUTPUT | OMAP_MUX_MODE0,
},
{
	.name = "uart3_tx_irtx.uart3_tx_irtx",
	.enable = OMAP_PIN_OUTPUT | OMAP_MUX_MODE0,
},
{
	.name = "uart3_rx_irrx.uart3_rx_irrx",
	.flags = OMAP_DEVICE_PAD_REMUX | OMAP_DEVICE_PAD_WAKEUP,
	.enable = OMAP_PIN_INPUT | OMAP_MUX_MODE0,
	.idle = OMAP_PIN_INPUT | OMAP_MUX_MODE0,
},
};

void __init beagle_serial_init( void ) 
{
	struct omap_board_data beagle_uart3_bdata;
	beagle_uart3_bdata.flags = 0;
	beagle_uart3_bdata.pads = beagle_uart3_pads;
	beagle_uart3_bdata.pads_cnt = ARRAY_SIZE(beagle_uart3_pads);
	beagle_uart3_bdata.id = 2;

	omap_serial_init_port( &beagle_uart3_bdata, NULL );
}

