package application;

import javafx.scene.image.Image;
import javafx.scene.image.PixelWriter;
import javafx.scene.image.WritableImage;
import javafx.scene.paint.Color;

public class MakeImage{
	private static int width,height;
	private static Image making;
	private static PixelWriter write;
	private static WritableImage newimage;
	private static Color[][] resultscolor = new Color[500][500];
	private static int[][] resultsargb = new int[500][500];
	MakeImage(int width,int height){
		this.width=width; this.height=height;
		newimage = new WritableImage(width,height);
		write = newimage.getPixelWriter();
		for(int i=0;i<width;i++){
	   		for(int j=0;j<height;j++){
	   			MakeImage.setPixel(i,j,Color.rgb(255,255,255));
	   		}
	   	}
	}
	static void setPixel(int x,int y,Color col){
		write.setColor(x,y,col);
		resultscolor[x][y]=col;
	}
	static void setArgb(int x,int y,int argb){
		write.setArgb(x, y, argb);
		resultsargb[x][y]=argb;
		return;
	}
   static WritableImage returnimage(){
   	return newimage;
   }
   static void update(){
   	for(int i=0;i<width;i++){
   		for(int j=0;j<height;j++){
   			MakeImage.setPixel(i,j,resultscolor[i][j]);
   		}
   	}
   }
}