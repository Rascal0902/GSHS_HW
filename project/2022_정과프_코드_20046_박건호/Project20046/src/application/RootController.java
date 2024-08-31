package application;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.fxml.Initializable;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.FileChooser;
import javafx.stage.FileChooser.ExtensionFilter;
import java.io.IOException;

public class RootController implements Initializable{
	
	@FXML TextField lightX;
	@FXML TextField lightY;
	@FXML TextField lightZ;
	@FXML TextField lightR;
	@FXML TextField lightG;
	@FXML TextField lightB;
	@FXML TextField savestring;
	@FXML ImageView image1;	
	@FXML ImageView image2;	
	@FXML Slider    power;
	@FXML Slider    ambient;
	@FXML ListView<String> list;
	
	int selected=0,now=0,minselected=0,maxselected=9;
	
    public void initialize(URL arg0,ResourceBundle arg1){
    	ChangeImage.lightX = new int[10];ChangeImage.lightY = new int[10];ChangeImage.lightZ = new int[10];
    	ChangeImage.lightR = new int[10];ChangeImage.lightG = new int[10];ChangeImage.lightB = new int[10];
    	ChangeImage.power = new float[10];ChangeImage.ambient = new float[10];
    	for(int i=0 ; i<10; i++){
    		ChangeImage.lightX[i]=150;ChangeImage.lightY[i]=150;ChangeImage.lightZ[i]=100000;
            ChangeImage.lightR[i]=255;ChangeImage.lightG[i]=255;ChangeImage.lightB[i]=255;
            ChangeImage.power[i] = 0;ChangeImage.ambient[i] = 1;
    	}
    	power.valueProperty().addListener(new ChangeListener<Number>() {
            @Override
            public void changed(ObservableValue<? extends Number> observableValue, Number number, Number t1) {
            	ChangeImage.power[selected]=t1.floatValue();
            	try{
                	ChangeImage.update();
                	image2.setImage(ChangeImage.newImage);
                	System.out.println("show");
                	}catch(NullPointerException e){
                		System.out.println("no image loaded");
                	}
                	System.out.println();
            }
        });
    	ambient.valueProperty().addListener(new ChangeListener<Number>() {
            @Override
            public void changed(ObservableValue<? extends Number> observableValue, Number number, Number t1) {
            	ChangeImage.ambient[selected]=(float)t1.floatValue()/100;
            	try{
                	ChangeImage.update();
                	image2.setImage(ChangeImage.newImage);
                	System.out.println("show");
                	}catch(NullPointerException e){
                		System.out.println("no image loaded");
                	}
                	System.out.println();
            }
        });
    	list.setItems(FXCollections.observableArrayList());
    	list.getSelectionModel().selectedIndexProperty().addListener(new ChangeListener<Number>() {
    	@Override
    	public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {
    		
    	if(selected != 0)
    	{String strItem = list.getSelectionModel().getSelectedItem();
    	selected = Integer.parseInt(strItem.substring(5,6));
    	lightX.setText(Integer.toString(ChangeImage.lightX[selected]));
		lightY.setText(Integer.toString(ChangeImage.lightY[selected]));
		lightZ.setText(Integer.toString(ChangeImage.lightZ[selected]));
		lightR.setText(Integer.toString(ChangeImage.lightR[selected]));
		lightG.setText(Integer.toString(ChangeImage.lightG[selected]));
		lightB.setText(Integer.toString(ChangeImage.lightB[selected]));}
    	else{}
    	setting();
    	}
    	});
    }
    public void settingBtn(ActionEvent event){
    	setting();
	}
    public void setting(){
    	if(selected == 0){
        	System.out.println("nothing selected!!");
        	lightX.setText("");lightY.setText("");lightZ.setText("");
            lightR.setText("");lightG.setText("");lightB.setText("");
            }
        	else{
        	try{ChangeImage.lightX[selected] = Integer.parseInt((lightX.getText()).toString());}
        	catch(NumberFormatException e){ChangeImage.lightX[selected]=150;lightX.setText("150");}
        	try{ChangeImage.lightY[selected] = Integer.parseInt((lightY.getText()).toString());}
        	catch(NumberFormatException e){ChangeImage.lightY[selected]=150;lightY.setText("150");}
        	try{ChangeImage.lightZ[selected] = Integer.parseInt((lightZ.getText()).toString());}
        	catch(NumberFormatException e){ChangeImage.lightZ[selected]=100000;lightZ.setText("100000");}
        	try{ChangeImage.lightR[selected] = Integer.parseInt((lightR.getText()).toString());}
        	catch(NumberFormatException e){ChangeImage.lightR[selected]=255;lightR.setText("255");}
        	try{ChangeImage.lightG[selected] = Integer.parseInt((lightG.getText()).toString());}
        	catch(NumberFormatException e){ChangeImage.lightG[selected]=255;lightG.setText("255");}
        	try{ChangeImage.lightB[selected] = Integer.parseInt((lightB.getText()).toString());}
        	catch(NumberFormatException e){ChangeImage.lightB[selected]=255;lightB.setText("255");}
        	power.setValue(ChangeImage.power[selected]);
        	ambient.setValue(ChangeImage.ambient[selected]*100);
        	}
        	try{
        	ChangeImage.update();
        	image2.setImage(ChangeImage.newImage);
        	System.out.println("show");
        	}catch(NullPointerException e){
        		System.out.println("no image loaded");
        	}
        	System.out.println();
    }
    public void loadBtn(ActionEvent event)
	{
    	FileChooser fc = new FileChooser();
    	fc.setTitle("이미지 선택");
    	fc.setInitialDirectory(new File("C:/"));
        ExtensionFilter imgType = new ExtensionFilter("image file", "*.jpg", "*.png");
        fc.getExtensionFilters().add(imgType);
        ExtensionFilter txtType = new ExtensionFilter("text file", "*.txt", "*.doc");
        fc.getExtensionFilters().addAll(imgType, txtType);
        File selectedFile = fc.showOpenDialog(null);
        System.out.println(selectedFile);
        try {
			 FileInputStream fis = new FileInputStream(selectedFile);
             BufferedInputStream bis = new BufferedInputStream(fis);
             Image img = new Image(bis);
             image1.setImage(img);
             ChangeImage.setImage(img);
             ChangeImage.update();
             image2.setImage(ChangeImage.newImage);
            
        } catch (FileNotFoundException e) {
        	e.printStackTrace();}
		System.out.println("load");
	}
    public void saveBtn(ActionEvent event){
    	try {
			ChangeImage.saveImage(savestring.getText().toString());
		} catch (IOException e) {
			System.out.println("no Image!!!");
		}
		System.out.println("save");
	}
    public void exitBtn(ActionEvent event){
    	System.out.println("finished");
    	System.exit(0);
    }
    public void newBtn(ActionEvent event){
    	if(now >= maxselected){System.out.println("max lights!!");return;}
    	if(now==0){selected=1;}
    	now++;ChangeImage.now = now;
    	String temp = "light" + Integer.toString(now);
    	list.getItems().add(temp);
	}
    public void deleteBtn(ActionEvent event){
    	if(now <= minselected){System.out.println("min lights!!");return;}
    	ChangeImage.lightX[selected]=150;ChangeImage.lightY[selected]=150;ChangeImage.lightZ[selected]=100000;
        ChangeImage.lightR[selected]=255;ChangeImage.lightG[selected]=255;ChangeImage.lightB[selected]=255;
        ChangeImage.power[selected] = 0;ChangeImage.ambient[selected] = 1;
    	if(selected == now){selected--;}
    	list.getItems().remove("light" + Integer.toString(now));
    	now--;ChangeImage.now = now;
    }
}