//All functions can refer to RTL9021Ax_Sample_Code_Note_v0.1.pdf.


#include "rtl9021ax_sample_code_v01.h"

u16 param_check0[23*3]={0x0C02,19,0x0AB5,0x0C02,20,0x03B9,0x0C02,21,0x03B9,0x0C02,22,0x03B9,0x0C02,23,0x03B9,
						0x0C01,20,0x0200,0x0,0x8159,0x3303,0x0,0x815B,0x8A02,0x0,0x815D,0x0402,0x0,0x815F,0x9A01,
						0x0,0x8161,0x4601,0x0,0x8163,0x0301,0x0,0x8238,0x518C,0x0,0x81FD,0x517F,0x0BCC,16,0x00A9,
						0x0A85,21,0x1D63,0x0A85,22,0x1D63,0x0A85,23,0x1D63,0x0A6F,19,0x7940,0x0A68,23,0x1C8B,
						0x0BC4,19,0x0D0F,0x0,0x823A,0x5A28,0x0,0x81FF,0x5A28};
u16 param_check1[29]={0xE401,0xC709,0xA410,0xD713,0x5FEE,0xD711,0x62BC,0xD713,0x6090,0xA404,0xA040,0xE40E,0xA408,0xA080,0xA321,
					  0xA410,0xD710,0x12B1,0x8014,0xD713,0x5FEE,0x7E50,0x60AF,0xD710,0x11EE,0x041B,0xE407,0xA321,0xE0CF};

		
s16 RTL9021Ax_Initial_Configuration() {
	u32 mdio_data = 0;
	u32 timer = 2000; // set a 2ms timer
	
	
	// PHY Parameter Start //
	mdio_write(31, 0x0C02);
	mdio_write(19, 0x0AB5);
	mdio_write(20, 0x03B9);
	mdio_write(21, 0x03B9);
	mdio_write(22, 0x03B9);
	mdio_write(23, 0x03B9);
	mdio_write(31, 0x0C01);
	mdio_write(20, 0x0200);

	mdio_write(27, 0x8159);
	mdio_write(28, 0x3303);
	mdio_write(27, 0x815B);
	mdio_write(28, 0x8A02);
	mdio_write(27, 0x815D);
	mdio_write(28, 0x0402);
	mdio_write(27, 0x815F);
	mdio_write(28, 0x9A01);
	mdio_write(27, 0x8161);
	mdio_write(28, 0x4601);
	mdio_write(27, 0x8163);
	mdio_write(28, 0x0301);

	mdio_write(27, 0x8238);
	mdio_write(28, 0x518C);
	mdio_write(27, 0x81FD);
	mdio_write(28, 0x517F);

	mdio_write(31, 0x0BCC);
	mdio_write(16, 0x00A9);

	mdio_write(31, 0x0A85);
	mdio_write(21, 0x1D63);
	mdio_write(22, 0x1D63);
	mdio_write(23, 0x1D63);

	mdio_write(31, 0x0A6F);
	mdio_write(19, 0x7940); 
	mdio_write(31, 0x0A68);
	mdio_write(23, 0x1C8B);
	mdio_write(31, 0x0BC4);
	mdio_write(19, 0x0D0F); 

	mdio_write(27, 0x823A);
	mdio_write(28, 0x5A28);
	mdio_write(27, 0x81FF); 
	mdio_write(28, 0x5A28); 
	//

	mdio_write(27, 0xB820);
	mdio_write(28, 0x0010);
	mdio_write(27, 0xB830);
	mdio_write(28, 0x8000);
	do	
	{
		mdio_write(27, 0xB800);
		mdio_data = ((u16) mdio_read(28) & 0x0040);
		timer--;
		if (timer == 0) {
			return ERROR;
		}
	}while (mdio_data != 0x0040);
	
	mdio_write(27, 0x8020);
	mdio_write(28, 0x6100);
	mdio_write(27, 0xB82E);
	mdio_write(28, 0x0001);

	mdio_write(27, 0xB820);
	mdio_write(28, 0x0290);
	mdio_write(27, 0xEC12);
	mdio_write(28, 0x0000);
	mdio_write(27, 0xEC14);
	mdio_write(28, 0xE401);
	mdio_write(28, 0xC709);
	mdio_write(28, 0xA410);
	mdio_write(28, 0xD713);
	mdio_write(28, 0x5FEE);
	mdio_write(28, 0xD711);
	mdio_write(28, 0x62BC);
	mdio_write(28, 0xD713);
	mdio_write(28, 0x6090);
	mdio_write(28, 0xA404);
	mdio_write(28, 0xA040);
	mdio_write(28, 0xE40E);
	mdio_write(28, 0xA408);
	mdio_write(28, 0xA080);
	mdio_write(28, 0xA321);
	mdio_write(28, 0xA410);
	mdio_write(28, 0xD710);
	mdio_write(28, 0x12B1);
	mdio_write(28, 0x8014);
	mdio_write(28, 0xD713);
	mdio_write(28, 0x5FEE);
	mdio_write(28, 0x7E50);
	mdio_write(28, 0x60AF);
	mdio_write(28, 0xD710);
	mdio_write(28, 0x11EE);
	mdio_write(28, 0x041B);
	mdio_write(28, 0xE407);
	mdio_write(28, 0xA321);
	mdio_write(28, 0xE0CF);
	mdio_write(27, 0xEC1A);
	mdio_write(28, 0x0000);
	mdio_write(27, 0xEC0E);
	mdio_write(28, 0x07FF);
	mdio_write(27, 0xEC0C);
	mdio_write(28, 0x07FF);
	mdio_write(27, 0xEC0A);
	mdio_write(28, 0x07FF);
	mdio_write(27, 0xEC08);
	mdio_write(28, 0x07FF);
	mdio_write(27, 0xEC06);
	mdio_write(28, 0x07FF);
	mdio_write(27, 0xEC04);
	mdio_write(28, 0x07FF);
	mdio_write(27, 0xEC02);
	mdio_write(28, 0x07FF);
	mdio_write(27, 0xEC00);
	mdio_write(28, 0x80AB);
	mdio_write(27, 0xB820);
	mdio_write(28, 0x0210);


	mdio_write(27, 0xB82E);
	mdio_write(28, 0x0000);
	mdio_write(27, 0x8020);
	mdio_write(28, 0x0000);
	mdio_write(27, 0xB820);
	mdio_write(28, 0x0000);

	timer = 2000; // set a 2ms timer
	do
	{	
		mdio_write(27, 0xB800);
		mdio_data = ((u16) mdio_read(28) & 0x0040);
		timer--;
		if (timer == 0) {
			return ERROR;
		}
	}while (mdio_data != 0x0000);
	// End //

	return SUCCESS;
}

s16 RTL9021Ax_Initial_Configuration_Check(){
	u16 mdio_data = 0, mdio_data_temp;
	u16 mdio_data_chk = 0;
	u32 timer = 2000; // set a 2ms timer

	u16 page;
	u16 reg, i, param_address1, param_address2;
	
	for(i=0;i<23*3;i=i+3){
		page = param_check0[i];
		mdio_data_chk = param_check0[i+2];
		reg = param_check0[i+1];
		if(page == 0){
			mdio_write(27,reg);
			mdio_data = mdio_read(28);
		}
		else{
			mdio_write(31,page);
			mdio_data = mdio_read(reg);
		}
		if(mdio_data_chk!= mdio_data){
			DBGMSG(("%dth param error page=0x%04X reg=0x%04X data=0x%04X\r\n",i/3,page, reg, mdio_data));
			return ERROR;
		}
	}
	
	mdio_write(27, 0xB820);
	mdio_write(28, 0x0010);
	mdio_write(27, 0xB830);
	mdio_write(28, 0x8000);

	do
	{	
		mdio_write(27, 0xB800);
		mdio_data = ((u16) mdio_read(28) & 0x0040);
		timer--;
		if (timer == 0) {
			return ERROR;
		}
	}while (mdio_data != 0x0040);
	mdio_write(27, 0x8020);
	mdio_write(28, 0x6100);
	mdio_write(27, 0xB82E);
	mdio_write(28, 0x0001);

	param_address1 = 0;
	for(i=0;i<29;i++){
		mdio_write(31, 0xEC1);
		mdio_data_temp = mdio_read(17);
		mdio_data_temp&=~(0x1FF);
		param_address1 &= 0x1FF;
		mdio_write(17, (mdio_data_temp|param_address1));
		mdio_write(31, 0xEC1);
		mdio_data = mdio_read(18);
		mdio_data_chk = param_check1[i];
		if(mdio_data_chk!= mdio_data){
			DBGMSG(("check1 - %dth param error data=0x%04X  expected_data=0x%04X\r\n",i,mdio_data, mdio_data_chk));
			return ERROR;
		}
		param_address1 ++;
	}

	i++;
	mdio_write(27, 0xEC0E);
	mdio_data = mdio_read(28);
	mdio_data_chk = 0x07FF;
	if(mdio_data_chk!= mdio_data){
		DBGMSG(("check1 - %dth param error data=0x%04X  expected_data=0x%04X\r\n",i,mdio_data, mdio_data_chk));
		return ERROR;
	}

	i++;
	mdio_write(27, 0xEC0C);
	mdio_data = mdio_read(28);
	mdio_data_chk = 0x07FF;
	if(mdio_data_chk!= mdio_data){
		DBGMSG(("check1 - %dth param error data=0x%04X  expected_data=0x%04X\r\n",i,mdio_data, mdio_data_chk));
		return ERROR;
	}

	i++;
	mdio_write(27, 0xEC0A);
	mdio_data = mdio_read(28);
	mdio_data_chk = 0x07FF;
	if(mdio_data_chk!= mdio_data){
		DBGMSG(("check1 - %dth param error data=0x%04X  expected_data=0x%04X\r\n",i,mdio_data, mdio_data_chk));
		return ERROR;
	}

	i++;
	mdio_write(27, 0xEC08);
	mdio_data = mdio_read(28);
	mdio_data_chk = 0x07FF;
	if(mdio_data_chk!= mdio_data){
		DBGMSG(("check1 - %dth param error data=0x%04X  expected_data=0x%04X\r\n",i,mdio_data, mdio_data_chk));
		return ERROR;
	}

	i++;
	mdio_write(27, 0xEC06);
	mdio_data = mdio_read(28);
	mdio_data_chk = 0x07FF;
	if(mdio_data_chk!= mdio_data){
		DBGMSG(("check1 - %dth param error data=0x%04X  expected_data=0x%04X\r\n",i,mdio_data, mdio_data_chk));
		return ERROR;
	}

	i++;
	mdio_write(27, 0xEC04);
	mdio_data = mdio_read(28);
	mdio_data_chk = 0x07FF;
	if(mdio_data_chk!= mdio_data){
		DBGMSG(("check1 - %dth param error data=0x%04X  expected_data=0x%04X\r\n",i,mdio_data, mdio_data_chk));
		return ERROR;
	}

	i++;
	mdio_write(27, 0xEC02);
	mdio_data = mdio_read(28);
	mdio_data_chk = 0x07FF;
	if(mdio_data_chk!= mdio_data){
		DBGMSG(("check1 - %dth param error data=0x%04X  expected_data=0x%04X\r\n",i,mdio_data, mdio_data_chk));
		return ERROR;
	}

	i++;
	mdio_write(27, 0xEC00);
	mdio_data = mdio_read(28);
	mdio_data_chk = 0x80AB;
	if(mdio_data_chk!= mdio_data){
		DBGMSG(("check1 - %dth param error data=0x%04X  expected_data=0x%04X\r\n",i,mdio_data, mdio_data_chk));
		return ERROR;
	}
	

	mdio_write(27, 0xB82E);
	mdio_write(28, 0x0000);
	mdio_write(27, 0x8020);
	mdio_write(28, 0x0000);
	mdio_write(27, 0xB820);
	mdio_write(28, 0x0000);
	
	timer = 2000; // set a 2ms timer
	do
	{	
		mdio_write(27, 0xB800);
		mdio_data = ((u16) mdio_read(28) & 0x0040);
		timer--;
		if (timer == 0) {
			return ERROR;
		}
	}while (mdio_data != 0x0000);
	
	return SUCCESS;
	
}


