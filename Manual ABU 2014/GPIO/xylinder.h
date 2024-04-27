//----------------------------------------------------------------------
char xl1 = 0,xl2 = 0,xl3 = 0,xl4 = 0,xl5 = 0,xl6 = 0,xl7 = 0;
//================================= TAY GAP RA =====================================
 void Kich_Xylanh(void)
 {	
   if(!L2 && !TRIANGLE)       
    {
				bitha=0;        
				Xilanh53_ra_on;
				Xilanh53_ve_off;  
     } 
		else	Xilanh53_ra_off;  
     
 //================================= THU TAY VE ==================================
    
  if(!L2 && !X)       
    {    
				bitha=0;
				Xilanh53_ve_on;
				Xilanh53_ra_off;  
     }    
		else         Xilanh53_ve_off;

		 
//============================= KICH XILANH CHEO =======================================
	if(!L2 && !O)       
    {
        xl4 = ~xl4;
        while(!L2 && !O)
        {
						gp_update_btn();
      	    delay_us(10);
        }                
                   
        if(xl4)      Xilanh_cheo_on; 
        else         Xilanh_cheo_off; 
     }		 
//================================== KEP BANG TAY =======================================
	if(!RJOY)      
    {
        xl3 = ~xl3;
        while(!RJOY)
        {		
						gp_update_btn();
      	    delay_us(10);
        }                
                   
        if(xl3)      Xilanh_kep_off; 
        else         Xilanh_kep_on;  
     }
		
//============================= KICH XILANH CHEO =======================================
	if(!L2 && !SQUARE)       
		 {            
        xl5 = ~xl5;
        while(!L2 && !SQUARE)	
				{
						gp_update_btn();
						delay_us(5);
				}                            
        if(xl5)      Xilanh50_on; 
        else         Xilanh50_off; 	
     }
	  if(!LJOY)       
    {
        Xilanh_mode_on;
				delay_ms(500);	Xilanh_mode_off;  
    } 
}


