 /*
  * sc7732s_thermistor.c - thermistor for SC7730S projects
  *
  * Copyright (C) 2014 Samsung Electronics
  * SangYoung Son <hello.son@samsung.com>
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <mach/sc7723s_thermistor.h>
#include <mach/sec_thermistor.h>

#if defined(CONFIG_SEC_THERMISTOR)
#if defined(CONFIG_MACH_COREPRIMEVE3G)
static struct sec_therm_adc_table temper_table_ap[] = {
	{456, 800}, /* 80 */
	{534, 750}, /* 75 */
	{626, 700}, /* 70 */
	{732, 650}, /* 65 */
	{849, 600}, /* 60 */
	{991, 550}, /* 55 */ 
	{1134, 500}, /* 50 */ 
	{1274, 460}, /* 46 */ 
	{1314, 450}, /* 45 */ 
	{1508, 400}, /* 40 */ 
	{1705, 350}, /* 35 */	
	{1908, 300}, /* 30 */  
	{2149, 250}, /* 25 */ 
	{2394, 200}, /* 20 */  
	{2639, 150}, /* 15 */ 
	{2876, 100}, /* 10 */  
	{3068, 50}, /* 5 */   
	{3261, 0}, /* 0 */	
	{3443, -50}, /* -5 */
	{3511, -70}, /* -7*/ 
	{3603, -100}, /* -10 */
	{3736, -150}, /* -15 */
	{3846, -200}, /* -20 */
};

static struct sec_therm_adc_table temper_table_dcxo[] = {
	{450, 800}, /* 80 */
	{560, 750}, /* 75 */
	{673, 700}, /* 70 */
	{788, 650}, /* 65 */
	{903, 600}, /* 60 */
	{1052, 550}, /* 55 */ 
	{1202, 500}, /* 50 */ 
	{1377, 450}, /* 45 */ 
	{1553, 400}, /* 40 */ 
	{1754, 350}, /* 35 */	
	{1955, 300}, /* 30 */  
	{2169, 250}, /* 25 */ 
	{2383, 200}, /* 20 */  
	{2588, 150}, /* 15 */ 
	{2793, 100}, /* 10 */  
	{2949, 50}, /* 5 */   
	{3106, 0}, /* 0 */	
	{3254, -50}, /* -5 */
	{3380, -100}, /* -10 */
	{3473, -150}, /* -15 */
	{3556, -200}, /* -20 */
};	
#elif defined(CONFIG_MACH_GRANDPRIMEVE3G)
static struct sec_therm_adc_table temper_table_ap[] = {
	{521 , 800},
	{572 , 750},
	{607 , 700},
	{659 , 650},
	{689 , 620},
	{710 , 600},
	{741 , 580},
	{780 , 550},
	{860 , 500},
	{898 , 480},
	{931 , 460},
	{946 , 450},
	{963 , 440},
	{1033 , 400},
	{1150 , 350},
	{1292 , 300},
	{1416 , 250},
	{1529 , 200},
	{1659 , 150},
	{1771 , 100},
	{1892 , 50},
	{2000 , 20},
	{2110 , 0},
	{2122 , -20},
	{2141 , -30},
	{2189 , -50},
	{2214 , -70},
	{2330 , -100},
	{2440 , -150},
	{2520 , -200},
};

static struct sec_therm_adc_table temper_table_dcxo[] = {
	{524 , 800},
	{550 , 750},
	{586 , 700},
	{655 , 650},
	{719 , 620},
	{758 , 600},
	{783 , 580},
	{876 , 550},
	{984 , 500},
	{1024 , 480},
	{1071 , 460},
	{1099 , 450},
	{1119 , 440},
	{1241 , 400},
	{1283 , 350},
	{1394 , 300},
	{1526 , 250},
	{1769 , 200},
	{1899 , 150},
	{2011 , 100},
	{2112 , 50},
	{2176 , 20},
	{2210 , 0},
	{2242 , -20},
	{2257 , -30},
	{2289 , -50},
	{2314 , -70},
	{2360 , -100},
	{2440 , -150},
	{2520 , -200},
};	
#else
static struct sec_therm_adc_table temper_table_ap[] = {
	{486 , 800},
	{564 , 750},
	{656 , 700},
	{762 , 650},
	{834 , 620},
	{885 , 600},
	{939 , 580},
	{1025 , 550},
	{1185 , 500},
	{1254 , 480},
	{1326 , 460},
	{1364 , 450},
	{1402 , 440},
	{1562 , 400},
	{1735 , 350},
	{1908 , 300},
	{2023 , 250},
	{2294 , 200},
	{2539 , 150},
	{2776 , 100},
	{2999 , 50},
	{3224 , 20},
	{3295 , 0},
	{3370 , -20},
	{3407 , -30},
	{3481 , -50},
	{3551 , -70},
	{3643 , -100},
	{3776 , -150},
	{3886 , -200},
};

static struct sec_therm_adc_table temper_table_dcxo[] = {
	{486 , 800},
	{564 , 750},
	{656 , 700},
	{762 , 650},
	{834 , 620},
	{885 , 600},
	{939 , 580},
	{1025 , 550},
	{1185 , 500},
	{1254 , 480},
	{1326 , 460},
	{1364 , 450},
	{1402 , 440},
	{1562 , 400},
	{1735 , 350},
	{1908 , 300},
	{2023 , 250},
	{2294 , 200},
	{2539 , 150},
	{2776 , 100},
	{2999 , 50},
	{3224 , 20},
	{3295 , 0},
	{3370 , -20},
	{3407 , -30},
	{3481 , -50},
	{3551 , -70},
	{3643 , -100},
	{3776 , -150},
	{3886 , -200},
};
#endif

static struct sec_therm_platform_data sec_therm_pdata = {
	.ap_adc_arr_size	= ARRAY_SIZE(temper_table_ap),
	.ap_adc_table	= temper_table_ap,
	.ap_channel = 3,
	.dcxo_adc_arr_size	= ARRAY_SIZE(temper_table_dcxo),
	.dcxo_adc_table	= temper_table_dcxo,
	.dcxo_channel = 2,
};


struct platform_device sec_device_thermistor = {
	.name = "sec-thermistor",
	.id = -1,
	.dev.platform_data = &sec_therm_pdata,
};

struct sec_therm_platform_data * fill_therm_pdata(struct platform_device *pdev)
{
	pdev->dev.platform_data = &sec_therm_pdata;
	pdev->id = -1;

	return &sec_therm_pdata;
}
#endif
