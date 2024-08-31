package application;

import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

import javafx.embed.swing.SwingFXUtils;
import javafx.scene.image.Image;
import javafx.scene.image.WritableImage;
import javafx.scene.paint.Color;

public class ChangeImage{
   public static int lightX[],lightY[],lightZ[],lightR[],lightG[],lightB[];
   public static float power[],ambient[];
   public static Image beforeImage ; 
   public static WritableImage temp;
   public static WritableImage newImage;
   public static int now=0;
   ChangeImage(){}
   static void setImage(Image image){
	     beforeImage = image;
	     TurnLight.width = (int) beforeImage.getWidth();
	     TurnLight.height = (int) beforeImage.getHeight();
   }
   static boolean saveImage(String base) throws IOException{
       File f = new File(base + ".png");
       return ImageIO.write(SwingFXUtils.fromFXImage(newImage, null),"png", f);
   }
   static void update(){
	   ImageInfo Info = new ImageInfo(beforeImage);
	     MakeImage t = new MakeImage((int)beforeImage.getWidth(),(int)beforeImage.getHeight());
	     for(int i=0;i<beforeImage.getWidth();i++){
	    		for(int j=0;j<beforeImage.getHeight();j++){
	    			MakeImage.setPixel(i,j,Color.rgb(ImageInfo.getRGB(i,j)[0],ImageInfo.getRGB(i,j)[1],ImageInfo.getRGB(i,j)[2]));
	    		}
	    	}
	   temp=MakeImage.returnimage();
	   for(int cnt=1; cnt<=now ; cnt++){
		   Info = new ImageInfo((Image)temp);
		   for(int i=0;i<beforeImage.getWidth();i++){
		    	 for(int j=0;j<beforeImage.getHeight();j++){
		    		 TurnLight.Red[i][j]= (float) ImageInfo.getRGB(i,j)[0];
		    		 TurnLight.Green[i][j]= (float) ImageInfo.getRGB(i,j)[1];
		    		 TurnLight.Blue[i][j]= (float) ImageInfo.getRGB(i,j)[2];
		    	 }
		     }
		   
             TurnLight.lightX=lightX[cnt];TurnLight.lightY=lightY[cnt];TurnLight.lightZ=lightZ[cnt];
             TurnLight.lightR=lightR[cnt];TurnLight.lightG=lightG[cnt];TurnLight.lightB=lightB[cnt];
             float[] temparray = new float[3];
             for(int k=0 ;k<3; k++){
             	temparray[k]=ambient[cnt];
             }
             TurnLight.power=power[cnt]; TurnLight.Ambient = temparray;
             
        for(int i=0;i<beforeImage.getWidth();i++){
	    	 for(int j=0;j<beforeImage.getHeight();j++){
	    		 TurnLight.lambert_color(i, j);
	    	 }
	     }
        
         MakeImage tmp = new MakeImage((int)beforeImage.getWidth(),(int)beforeImage.getHeight());
         
         for(int i=0;i<beforeImage.getWidth();i++){
	    	 for(int j=0;j<beforeImage.getHeight();j++){
	    		 Color col = TurnLight.lambert_color(i,j);
	    		 MakeImage.setPixel(i, j, col);
	    	 }
	     }
         
         temp = MakeImage.returnimage();
	   }
	   newImage = temp;
   }
}