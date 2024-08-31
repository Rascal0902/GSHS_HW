package application;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.paint.CycleMethod;
import javafx.scene.paint.LinearGradient;
import javafx.scene.paint.Stop;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage) throws IOException {
        Group root = new Group();

        Rectangle rect = new Rectangle(400, 400);
        drawBackground(rect);
        root.getChildren().add(rect);

        final Canvas canvas = new Canvas(200, 200);
        canvas.setTranslateX(100);
        canvas.setTranslateY(100);
        reset(canvas, Color.BLUE);

        final GraphicsContext gc = canvas.getGraphicsContext2D();

        canvas.addEventHandler(MouseEvent.MOUSE_DRAGGED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                gc.clearRect(event.getX() - 2, event.getY() - 2, 5, 5);
            }
        });

        canvas.addEventHandler(MouseEvent.MOUSE_CLICKED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                if(event.getClickCount() > 1)
                    reset(canvas, Color.BLUE);
            }
        });

        root.getChildren().add(canvas);
        Scene scene = new Scene(root, 400, 400);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void drawBackground(Rectangle rect) {
        rect.setFill(new LinearGradient(0, 0, 1, 1, true, CycleMethod.REPEAT,
                    new Stop(0, Color.RED), new Stop(1, Color.YELLOW)));
    }

    private void reset(Canvas canvas, Color color) {
        GraphicsContext gc = canvas.getGraphicsContext2D();
        gc.setFill(color);
        gc.fillRect(0, 0, canvas.getWidth(), canvas.getHeight());
    }

    public static void main(String[] args) {
        launch();
    }
}
