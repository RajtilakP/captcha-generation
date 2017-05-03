#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>




main()
{
   int i = 0, key, num, midx, gd = DETECT, gm;
   char a[10];

   initgraph(&gd,&gm,"C:\\TC\\BGI");

   midx = getmaxx()/2;

   settextstyle(SCRIPT_FONT,HORIZ_DIR,5);
   settextjustify(CENTER_TEXT,CENTER_TEXT);
   setcolor(WHITE);
   outtextxy(midx,20,"CAPTCHA Generator");

   settextstyle(SCRIPT_FONT,HORIZ_DIR,2);
   outtextxy(midx,60,"\nBy Rajtilak Pattanaik \n(14SCSE101433)");
   outtextxy(midx,125,"Press any key to change the generated random code \"captcha\"");
   outtextxy(midx,150,"Press escape key to exit...");
 
   setcolor(WHITE);
   setviewport(100,200,600,400,1);
   setcolor(RED);
   randomize();
 
   while(1)
   {
      while(i<6)
      {
         num = random(3);
 
         if ( num == 0 )
            a[i] = 65 + random(26);     /* 65 is the ASCII value of A */
         else if ( num == 1)
            a[i] = 97 + random(26);     /* 97 is the ASCII value of a */
         else
            a[i] = 48 + random(10);     /* 48 is the ASCII value of 0 */
         i++;
      }
      a[i] = '\0';
      outtextxy(210,100,a);
      key = getch();
 
      if( key == 27 )                     /* escape key*/
         exit(0);
      clearviewport();
      i = 0;
   }
}