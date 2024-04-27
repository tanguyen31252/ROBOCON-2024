//            CHUONG TRINH NANG HA TRUC TU TU
void lcdViewer(void);
 
void gp_update_btn(void);

 void Nang_Truc(char speed_auto,char vitri)
 {	
				switch (vitri) 
					 {
					case 1:	if(cb_NC_1) 	      	mor_nang=speed_auto,mor_nang_up;		  
												else mor_nang=2; 
									break;
					case 2:	if(cb_NC_2) 	    		mor_nang=speed_auto,mor_nang_up;		  
												else mor_nang=2; 
									break;
					case 3: if(cb_NC_3) 					mor_nang=speed_auto,mor_nang_up;
												else mor_nang=2; 	
									break;
					case 4: if(cb_NC_4) 					mor_nang=speed_auto,mor_nang_up;
												else mor_nang=2;
									break;
					case 5: if(cb_NC_5) 			  	mor_nang=speed_auto,mor_nang_up;	 
										else mor_nang=2; 	
								break;
					case 6: if(cb_NC_6) 					mor_nang=speed_auto,mor_nang_up;	 
										else mor_nang=2; 	
								break;
					case 7: if(cb_NC_7) 					mor_nang=speed_auto,mor_nang_up;
										else mor_nang=2;
									break;
					case 8: if(cb_NC_8) 					mor_nang=speed_auto,mor_nang_up;	 
										else mor_nang=2; 	
								break;
					case 9: if(cb_NC_9) 					mor_nang=speed_auto,mor_nang_up;	 
										else mor_nang=2; 	
								break;
					case 10: if(cb_NC_10) 					mor_nang=speed_auto,mor_nang_up;	 
										else mor_nang=2; 	
								break;
							
						}; 
 }
 
 void Ha_Truc(char speed_auto,char vitri)
 {
		switch (vitri) 
					 {
					case 1:	if(cb_NC_1) 	      		mor_nang=speed_auto,mor_nang_down;		  
												else mor_nang=2; 
									break;
					case 2:	if(cb_NC_2) 	      		mor_nang=speed_auto,mor_nang_down;		  
												else mor_nang=2; 
									break;
					case 3: if(cb_NC_3) 						mor_nang=speed_auto,mor_nang_down;
												else mor_nang=2; 	
									break;
					case 4: if(cb_NC_4) 						mor_nang=speed_auto,mor_nang_down;
												else mor_nang=2;
									break;
					case 5: if(cb_NC_5) 			  		mor_nang=speed_auto,mor_nang_down;	 
										else mor_nang=2; 	
								break;
					case 6: if(cb_NC_6) 						mor_nang=speed_auto,mor_nang_down;	 
										else mor_nang=2; 	
								break;
					case 7: if(cb_NC_7) 						mor_nang=speed_auto,mor_nang_down;
												else mor_nang=2;
									break;
					case 8: if(cb_NC_8) 						mor_nang=speed_auto,mor_nang_down;	 
										else mor_nang=2; 	
								break;	
					case 9: if(cb_NC_9) 						mor_nang=speed_auto,mor_nang_down;	 
										else mor_nang=2; 	
								break;
					case 10: if(cb_NC_10) 					mor_nang=speed_auto,mor_nang_down;	 
										else mor_nang=2; 	
								break;
						}; 
 }
 
 //************************* chuong trinh nang truc tai cho ************************

 void Nang_Truc_While(char speed_auto,int vitri)
{
									mor_nang=speed_auto,mor_nang_up;	
		switch (vitri) 
	 {
					case 1:	while(cb_NC_1) 			    if(wantExit()) return; 	
													mor_nang=2; 
								break;
					case 2:	while(cb_NC_2) 	  			if(wantExit()) return; 	
													mor_nang=2; 
								break;
					case 3: while(cb_NC_3) 					if(wantExit()) return; 	
													mor_nang=2; 
								break;
					case 4: while(cb_NC_4) 		    	if(wantExit()) return; 	
													mor_nang=2; 
								break;
		      case 5: while(cb_NC_5) 			 		if(wantExit()) return; 
										      mor_nang=2; 	
								break;
					case 6: while(cb_NC_6) 					if(wantExit()) return; 
										      mor_nang=2; 	
								break;
					case 7: while(cb_NC_7) 			  	if(wantExit()) return; 	
													mor_nang=2;
								break;
		      case 8: while(cb_NC_8) 					if(wantExit()) return; 
										      mor_nang=2; 	
								break;
					case 9: while(cb_NC_9) 					if(wantExit()) return; 
										      mor_nang=2; 	
								break;
					case 10: while(cb_NC_10) 				if(wantExit()) return; 
										      mor_nang=2; 	
								break;		  				  
    }; 
}

// ************************* chuong trinh ha truc tai cho ************************
void Ha_Truc_While(char speed_auto,int vitri)
{
										mor_nang=speed_auto,mor_nang_down;	
		switch (vitri) 
	 {
					case 1:	while(cb_NC_1) 			    if(wantExit()) return; 	
													mor_nang=2; 
								break;
					case 2:	while(cb_NC_2) 	  			if(wantExit()) return; 	
													mor_nang=2; 
								break;
					case 3: while(cb_NC_3) 					if(wantExit()) return; 	
													mor_nang=2; 
								break;
					case 4: while(cb_NC_4) 		    	if(wantExit()) return; 	
													mor_nang=2; 
								break;
		      case 5: while(cb_NC_5) 			 		if(wantExit()) return; 
										      mor_nang=2; 	
								break;
					case 6: while(cb_NC_6) 					if(wantExit()) return; 
										      mor_nang=2; 	
								break;
					case 7: while(cb_NC_7) 			  	if(wantExit()) return; 	
													mor_nang=2;
								break;
		      case 8: while(cb_NC_8) 					if(wantExit()) return; 
										      mor_nang=2; 	
								break;
					case 9: while(cb_NC_9) 					if(wantExit()) return; 
										      mor_nang=2; 	
								break;
					case 10: while(cb_NC_10) 				if(wantExit()) return; 
										      mor_nang=2; 	
								break;
				  				  
    }; 
}
// ************************* chuong trinh tay truot ra ************************
 
void Truot_Ra(char speed_auto,char vitri)
 {
    	
				switch (vitri) 
					 {
				  case 1:	if(cb_NC_TAY_1) 	          		mor_ngang=speed_auto,mor_ngang_next;		  
												else mor_ngang=2; 
									break;
				  case 2:	if(cb_NC_TAY_2) 	          		mor_ngang=speed_auto,mor_ngang_next;		  
												else mor_ngang=2; 
									break;
				  case 3:	if(cb_NC_TAY_3) 	          		mor_ngang=speed_auto,mor_ngang_next;		  
												else mor_ngang=2; 
									break;
				  case 4:	if(cb_NC_TAY_4) 	          		mor_ngang=speed_auto,mor_ngang_next;		  
												else mor_ngang=2; 
									break;
				  case 5:	if(cb_NC_TAY_5) 	          		mor_ngang=speed_auto,mor_ngang_next;		  
												else mor_ngang=2; 
									break;
				  case 6:	if(cb_NC_TAY_6) 	          		mor_ngang=speed_auto,mor_ngang_next;		  
												else mor_ngang=2; 
									break;
					case 7:	if(cb_NC_TAY_7) 	          		mor_ngang=speed_auto,mor_ngang_next;		  
												else mor_ngang=2; 
									break;
					case 8:	if(cb_NC_TAY_8) 	          		mor_ngang=speed_auto,mor_ngang_next;		  
												else mor_ngang=2; 
									break;
						}; 
 }

// ************************* chuong trinh tay truot vao ************************
 
void Truot_Vao(char speed_auto,char vitri)
 {
    	
				switch (vitri) 
					 {
				  case 1:	{if(cb_NC_TAY_1) 	          		mor_ngang=speed_auto,mor_ngang_back;		  
												else mor_ngang=2; 
					}
									break;
				  case 2:	if(cb_NC_TAY_2) 	          		mor_ngang=speed_auto,mor_ngang_back;		  
												else mor_ngang=2; 
									break;
				  case 3:	if(cb_NC_TAY_3) 	          		mor_ngang=speed_auto,mor_ngang_back;		  
												else mor_ngang=2; 
									break;
				  case 4:	if(cb_NC_TAY_4) 	          		mor_ngang=speed_auto,mor_ngang_back;		  
												else mor_ngang=2; 
									break;
				  case 5:	if(cb_NC_TAY_5) 	          		mor_ngang=speed_auto,mor_ngang_back;		  
												else mor_ngang=2; 
									break;
				  case 6:	if(cb_NC_TAY_6) 	          		mor_ngang=speed_auto,mor_ngang_back;		  
												else mor_ngang=2; 
									break;
					case 7:	if(cb_NC_TAY_7) 	          		mor_ngang=speed_auto,mor_ngang_back;		  
												else mor_ngang=2; 
									break;
				  case 8:	if(cb_NC_TAY_8) 	          		mor_ngang=speed_auto,mor_ngang_back;		  
												else mor_ngang=2; 
									break;
						}; 
 }
// ************************* chuong trinh tay truot ra tai cho ************************
 
 void Truot_Ra_While(char speed_auto,char vitri)
 {
											mor_ngang=speed_auto,mor_ngang_next;	
    	
				switch (vitri) 
					 {
					case 1:	while(cb_NC_TAY_1) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 2:	while(cb_NC_TAY_2) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 3:	while(cb_NC_TAY_3) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 4:	while(cb_NC_TAY_4) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 5:	while(cb_NC_TAY_5) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 6:	while(cb_NC_TAY_6) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 7:	while(cb_NC_TAY_7) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 8:	while(cb_NC_TAY_8) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
						}; 
 }
 
 // ************************* chuong trinh tay truot vao tai cho ************************

 
 void Truot_Vao_While(char speed_auto,char vitri)
 {
											mor_ngang=speed_auto,mor_ngang_back;	
    	
				switch (vitri) 
					 {
					case 1:	while(cb_NC_TAY_1) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 2:	while(cb_NC_TAY_2) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 3:	while(cb_NC_TAY_3) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 4:	while(cb_NC_TAY_4) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 5:	while(cb_NC_TAY_5) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 6:	while(cb_NC_TAY_6) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 7:	while(cb_NC_TAY_7) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
					case 8:	while(cb_NC_TAY_8) 	           if(wantExit()) return; 			  
											 mor_ngang=2; 
									break;
						}; 
 }



//				//================================ NANG HA TRUC ==============================
//				//================================ NANG HA TRUC ==============================
//				//================================ NANG HA TRUC ==============================

void Nang_truc()
{
		char speed_nang_ha;
		if(!L1) 	speed_nang_ha = 150;
		else  		speed_nang_ha = 100; 
	
		if(R2 && L2 && !O && cb_NC_10)		      							{mor_nang = speed_nang_ha; mor_nang_down;}
		else if(R2 && L2 && !SQUARE && cb_NC_1)		    		{mor_nang = speed_nang_ha; mor_nang_up;  }
		else						 			  mor_nang = 2;
}

				//================================ TRUOT TRUC NGANG ==============================
				//================================ TRUOT TRUC NGANG ==============================
				//================================ TRUOT TRUC NGANG ==============================

void Truot_ngang()
{
	int speed;
					if(!L1) 	speed = 150;
							else  speed = 80; 
					if(R2 && L2 &&!TRIANGLE && cb_NC_TAY_1)						      {mor_ngang = speed; mor_ngang_next;}
							else if(R2 && L2 && !X && cb_NC_TAY_8)							{mor_ngang = speed; mor_ngang_back;}
							else								 			mor_ngang = 2;
}
				//================================ RESET TRUOT TRUC NGANG ==============================
				//================================ RESET TRUOT TRUC NGANG ==============================
				//================================ RESET TRUOT TRUC NGANG ==============================

void Reset_Truot_ngang()
{
		bitha=0;
		Xilanh_kep_on;delay_ms(100);Xilanh_cheo_off;
		Xilanh_mode_off,Xilanh53_ra_off,Xilanh50_off,Xilanh53_ve_on;
		while(cb_NC_TAY_8)
				{ 
						mor_ngang = 100;mor_ngang_back;
						if(wantExit()) return; 
				}
						mor_ngang=2;
		while(cb_NC_10)
				{ 
						mor_nang = 120;mor_nang_down;
						if(wantExit()) return; 
				}
						mor_nang=2;
		Reset_encoder_doc(),Reset_encoder_ngang();
}



