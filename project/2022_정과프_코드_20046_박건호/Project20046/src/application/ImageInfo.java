package application;

import java.awt.image.BufferedImage;

import javafx.embed.swing.SwingFXUtils;
import javafx.scene.image.Image;
import javafx.scene.image.PixelReader;
import javafx.scene.paint.Color;

public class ImageInfo{
	    public static int width;
	    public static int height;
	    private static boolean hasAlphaChannel;
	    private static int pixelLength;
	    private static int[] pixels = new int[10000000];
	    PixelReader pixelReader;
	    
	    ImageInfo(Image image) {
	    	width = (int) image.getWidth();
	        height = (int) image.getHeight();
	        BufferedImage buffered = SwingFXUtils.fromFXImage(image, null);
	        hasAlphaChannel = buffered.getAlphaRaster() != null;
	        pixelLength = 3;
	        if (hasAlphaChannel)
	            pixelLength = 4;
	        
	        pixelReader = image.getPixelReader();
	    	if (pixelReader == null) {
	            System.out.println("not Readable");
	        }
	    	for (int y = 0; y < height; y++) {
	            for (int x = 0; x < width; x++) {
	                Color color = pixelReader.getColor(x, y);
	                int pos = (y * pixelLength * width) + (x * pixelLength);
	                if (hasAlphaChannel)
                        pixels[pos++] = (int) color.getBrightness(); // Alpha
	        	        pixels[pos++] = (int) (color.getBlue()*255); // Blue
	        	        pixels[pos++] = (int) (color.getGreen()*255); // Green
	        	        pixels[pos++] = (int) (color.getRed()*255); // Red
	            }
	        }
	    }
	    static int[] getRGB(int x, int y) {
	        int pos = (y * pixelLength * width) + (x * pixelLength);
	        int argb = 0;
	        short rgb[] = new short[4];
	        int save[] = new int[5];
	        if (hasAlphaChannel)
	        rgb[3] = (short) (pixels[pos++] & 0xFF); // Alpha
	        rgb[2] = (short) (pixels[pos++] & 0xFF); // Blue
	        rgb[1] = (short) (pixels[pos++] & 0xFF); // Green
	        rgb[0] = (short) (pixels[pos++] & 0xFF); // Red
	        //System.out.printf("image %d %d : %d %d %d\n",x,y,rgb[0],rgb[1],rgb[2]);
	        if(hasAlphaChannel){
	             argb += (((int) rgb[3] & 0xff) << 24); // alpha
	             argb += ((int)  rgb[2] & 0xff); // blue
	             argb += (((int)  rgb[1] & 0xff) << 8); // green
	             argb += (((int) rgb[0] & 0xff) << 16); // red
	        }
	        else
	        {
	             argb += -16777216; // 255 alpha
	             argb += ((int)  rgb[2] & 0xff); // blue
		         argb += (((int)  rgb[1] & 0xff) << 8); // green
		         argb += (((int) rgb[0] & 0xff) << 16); // red
	        }
	        for(int i=0;i<3;i++){save[i]=rgb[i];}
	        save[4]=argb;
	        return save;
	    }
	    static int getArgb(short R,short G,short B,short alpha){
	    	int argb=0;
	    	argb += (((int) alpha & 0xff) << 24); // alpha
            argb += ((int)  B & 0xff); // blue
            argb += (((int) G & 0xff) << 8); // green
            argb += (((int) R & 0xff) << 16); // red
        return argb;
	    }
	    static int getArgb(short R,short G,short B){
	    	int argb=0;
	    	argb += -16777216; // 255 alpha
            argb += ((int)  B & 0xff); // blue
	        argb += (((int) G & 0xff) << 8); // green
	        argb += (((int) R & 0xff) << 16); // red
	        return argb;
	    }
}