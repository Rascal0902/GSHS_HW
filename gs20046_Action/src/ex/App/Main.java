package ex.App;
	
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;


public class Main extends Application {
	@Override
	public void start(Stage primaryStage) {
		try {
			HBox root = new HBox();
			root.setPrefSize(200,50);
			root.setAlignment(Pos.CENTER);
			root.setSpacing(20);
			
			Button btn1= new Button(" apple ");
			Button btn2= new Button(" pear ");
			
			root.getChildren().addAll(btn1,btn2);
			
			Scene scene = new Scene(root);
			primaryStage.setScene(scene);
			primaryStage.setScene(scene);
			
			btn1.setOnAction(new EventHandler<ActionEvent>(){
				public void handle(ActionEvent event){
					System.out.println("APPLE");
				}
			});
			btn2.setOnAction(event->System.out.println("PEAR"));
		
			primaryStage.setOnCloseRequest(event->System.out.println("Á¾·á"));
			
			primaryStage.show();
		
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		launch(args);
	}
}
