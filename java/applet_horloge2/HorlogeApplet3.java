   import java.util.*;
   import java.awt.*;
   import java.applet.*;

   public class HorlogeApplet3 extends Applet implements Runnable {
      Thread timer = null;
      int lastxs=0, lastys=0, lastxm=0, lastym=0, lastxh=0, lastyh=0;
      Date date = new Date();

      String lastDate = date.toLocaleString();
      Font F = new Font("TimesRoman", Font.PLAIN, 14);
      Date dat = null;
      Color fgcol = Color.blue;
      Color fgcol2 = Color.darkGray;
   
      public void init() {
         int x,y;
      // recuperer les 3 valeurs passees en parametre dans la page HTML
         try {
            setBackground(new Color(Integer.parseInt(getParameter("bgcolor"),16)));
         } 
            catch (Exception E) { 
            }
         try {
            fgcol = new Color(Integer.parseInt(getParameter("fgcolor1"),16));
         } 
            catch (Exception E) { 
            }
         try {
            fgcol2 = new Color(Integer.parseInt(getParameter("fgcolor2"),16));
         } 
            catch (Exception E) { 
            }
         resize(300,300);           
      }
   
      public void placerPoints(int x0, int y0, int x, int y, Graphics g) {
      
         g.drawLine(x0+x,y0+y,x0+x,y0+y);
         g.drawLine(x0+y,y0+x,x0+y,y0+x);
         g.drawLine(x0+y,y0-x,x0+y,y0-x);
         g.drawLine(x0+x,y0-y,x0+x,y0-y);
         g.drawLine(x0-x,y0-y,x0-x,y0-y);
         g.drawLine(x0-y,y0-x,x0-y,y0-x);
         g.drawLine(x0-y,y0+x,x0-y,y0+x);
         g.drawLine(x0-x,y0+y,x0-x,y0+y);
      }
   
      public void cercle(int x0, int y0, int r, Graphics g) {
         int x,y;
         float d;
      
         x=0;
         y=r;
         d=5/4-r;
         placerPoints(x0,y0,x,y,g);
      
         while (y>x){
            if (d<0) {
               d=d+2*x+3;
               x++;
            }
            else {
               d=d+2*(x-y)+5;
               x++;
               y--;
            }
            placerPoints(x0,y0,x,y,g);
         }
      }
   
      public void paint(Graphics g) {
         int xh, yh, xm, ym, xs, ys, s, m, h, xcenter, ycenter;
         String today;
      
         dat = new Date();
         s = dat.getSeconds();
         m = dat.getMinutes();
         h = dat.getHours();
         today = dat.toLocaleString();
         xcenter=80;
         ycenter=55;
          
         xs = (int)(Math.cos(s * 3.14f/30 - 3.14f/2) * 45 + xcenter);
         ys = (int)(Math.sin(s * 3.14f/30 - 3.14f/2) * 45 + ycenter);
         xm = (int)(Math.cos(m * 3.14f/30 - 3.14f/2) * 40 + xcenter);
         ym = (int)(Math.sin(m * 3.14f/30 - 3.14f/2) * 40 + ycenter);
         xh = (int)(Math.cos((h*30 + m/2) * 3.14f/180 - 3.14f/2) * 30 + xcenter);
         yh = (int)(Math.sin((h*30 + m/2) * 3.14f/180 - 3.14f/2) * 30 + ycenter);
      
      // Pour dessiner le cercle et les nombres
      
         g.setFont(F);
         g.setColor(fgcol);
         cercle(xcenter,ycenter,50,g);
         g.setColor(fgcol2);
         g.drawString("9",xcenter-45,ycenter+3); 
         g.drawString("3",xcenter+40,ycenter+3);
         g.drawString("12",xcenter-5,ycenter-37);
         g.drawString("6",xcenter-3,ycenter+45);
      
      // Effacer si necessaire et retracer
      
         g.setColor(getBackground());
         if (xs != lastxs || ys != lastys) {
            g.drawLine(xcenter, ycenter, lastxs, lastys);
            g.drawString(lastDate, 5, 125);
         }
         if (xm != lastxm || ym != lastym) {
            g.drawLine(xcenter, ycenter-1, lastxm, lastym);
            g.drawLine(xcenter-1, ycenter, lastxm, lastym); }
         if (xh != lastxh || yh != lastyh) {
            g.drawLine(xcenter, ycenter-1, lastxh, lastyh);
            g.drawLine(xcenter-1, ycenter, lastxh, lastyh); }
         g.setColor(fgcol2);
         g.drawString(today, 5, 125);  
         g.drawLine(xcenter, ycenter, xs, ys);
         g.setColor(fgcol);
         g.drawLine(xcenter, ycenter-1, xm, ym);
         g.drawLine(xcenter-1, ycenter, xm, ym);
         g.drawLine(xcenter, ycenter-1, xh, yh);
         g.drawLine(xcenter-1, ycenter, xh, yh);
         lastxs=xs; lastys=ys;
         lastxm=xm; lastym=ym;
         lastxh=xh; lastyh=yh;
         lastDate = today;
         dat=null;
      }
   
      public void start() {
         if(timer == null)
         {
            timer = new Thread(this);
            timer.start();
         }
      }
   
      public void stop() {
         timer = null;
      }
   
      public void run() {
         while (timer != null) {
            try {Thread.sleep(100);} 
               catch (InterruptedException e){
               }
            repaint();
         }
         timer = null;
      }
   
      public void update(Graphics g) {
         paint(g);
      }
   }
