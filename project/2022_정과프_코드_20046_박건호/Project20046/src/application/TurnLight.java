package application;

import javafx.scene.paint.Color;

class TurnLight{
   static int height,width;
   static float[][] Red = new float[500][500];
   static float[][] Green = new float[500][500];
   static float[][] Blue = new float[500][500];
   static float[][] newRed = new float[500][500];
   static float[][] newGreen = new float[500][500];
   static float[][] newBlue = new float[500][500];
   static float lightX,lightY,lightZ;
   static float lightR,lightG,lightB;
   static float power;
   static float[] Ambient ={(float)0.7,(float)0.7,(float)0.7};
   static Color ambient_color(int x,int y){
   	float R,G,B;
   	R = Red[x][y]*Ambient[0];
   	G = Green[x][y]*Ambient[1];
   	B = Blue[x][y]*Ambient[2];
   	return Color.rgb((int)R, (int)G, (int)B);
   }
   static Color diffuse_color(int x,int y){
   	float R,G,B;
   	float[] lightVector = { lightX - x , lightY - y, lightZ };
   	float mag = (float)Math.sqrt((lightX-x)*(lightX-x)+(lightY-y)*(lightY-y)+lightZ*lightZ);
   	for(int i=0 ; i<3 ; i++ ){lightVector[i]/=mag;}
   	float cosine = lightVector[2];
   	float lambertfactor = Math.max(cosine, 0);
   	float luminosity = 1/(1+mag*mag);
   	R = Math.min(Red[x][y]*power*2*lightR*lambertfactor*luminosity,255);
   	G = Math.min(Green[x][y]*power*2*lightG*lambertfactor*luminosity,255);
   	B = Math.min(Blue[x][y]*power*2*lightB*lambertfactor*luminosity,255);
   	return Color.rgb((int)R, (int)G, (int)B);
   }
   static Color lambert_color(int x,int y){
   	Color ambient = ambient_color(x,y);
   	Color diffuse = diffuse_color(x,y);
   	float finalR,finalG,finalB;
   	finalR=(float) Math.min(((ambient.getRed()+diffuse.getRed())*255),255);
   	finalG=(float) Math.min(((ambient.getGreen()+diffuse.getGreen())*255),255);
   	finalB=(float) Math.min(((ambient.getBlue()+diffuse.getBlue())*255),255);
   	return Color.rgb((int)finalR,(int)finalG,(int)finalB);
   }
}
