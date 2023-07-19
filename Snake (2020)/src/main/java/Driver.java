import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.StackPane;
import javafx.scene.media.AudioClip;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicLong;

public class Driver extends Application {
    boolean isDead = false;
    Text time = new Text();
    Text lvl = new Text();
    Text high = new Text();
    Text scoreNow  = new Text();
    static ArrayList<ImageView> snake = new ArrayList<>();
    static ArrayList<ImageView> fruit = new ArrayList<>();
    static int currLevel = 1;
    //static int highestScore = 0;
    static int currSpeed = 20;
    static int highScore = 0;
    static int score = 0;
    static int timeRemain = 30;
    AudioClip fruitCapture = new AudioClip(getClass().getClassLoader().getResource("fruit.mp3").toString());
    AudioClip gameOver = new AudioClip(getClass().getClassLoader().getResource("gameOver.mp3").toString());
    AudioClip click = new AudioClip(getClass().getClassLoader().getResource("click.mp3").toString());
    AudioClip click2 = new AudioClip(getClass().getClassLoader().getResource("click2.mp3").toString());

    static AnimationTimerStatus timer;
    Group toShow = new Group();
    long limit = 1000000000;
    AtomicLong finalLimit = new AtomicLong(limit);
    ImageView base = new ImageView( new Image("base20.jpg", true) );
    Scene level1 = new Scene(toShow, 1280, 800);
    AtomicInteger dir = new AtomicInteger(0);

    public void lv1Fruit() {
        fruit.clear();
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(0).setX(640);
        fruit.get(0).setY(100);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(1).setX(640);
        fruit.get(1).setY(200);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(2).setX(640);
        fruit.get(2).setY(300);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(3).setX(340);
        fruit.get(3).setY(300);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(4).setX(940);
        fruit.get(4).setY(300);

        for (ImageView f : fruit) {
            toShow.getChildren().add(f);
        }
    }

    public void lv2Fruit() {
        fruit.clear();
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(0).setX(640);
        fruit.get(0).setY(100);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(1).setX(640);
        fruit.get(1).setY(200);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(2).setX(640);
        fruit.get(2).setY(300);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(3).setX(340);
        fruit.get(3).setY(300);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(4).setX(940);
        fruit.get(4).setY(300);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(5).setX(340);
        fruit.get(5).setY(600);
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(6).setX(940);
        fruit.get(6).setY(600);
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(7).setX(340);
        fruit.get(7).setY(400);
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(8).setX(940);
        fruit.get(8).setY(400);
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(9).setX(640);
        fruit.get(9).setY(700);

        for (ImageView f : fruit) {
            toShow.getChildren().add(f);
        }
    }

    public void lv3Fruit() {
        fruit.clear();
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(0).setX(640);
        fruit.get(0).setY(100);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(1).setX(640);
        fruit.get(1).setY(200);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(2).setX(640);
        fruit.get(2).setY(300);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(3).setX(340);
        fruit.get(3).setY(300);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(4).setX(940);
        fruit.get(4).setY(300);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(5).setX(340);
        fruit.get(5).setY(600);
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(6).setX(940);
        fruit.get(6).setY(600);
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(7).setX(340);
        fruit.get(7).setY(400);
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(8).setX(940);
        fruit.get(8).setY(400);
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(9).setX(640);
        fruit.get(9).setY(700);

        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(10).setX(140);
        fruit.get(10).setY(600);
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(11).setX(1040);
        fruit.get(11).setY(600);
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(12).setX(140);
        fruit.get(12).setY(100);
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(13).setX(1040);
        fruit.get(13).setY(100);
        fruit.add(new ImageView( new Image("fruit20.png", true) ));
        fruit.get(14).setX(640);
        fruit.get(14).setY(760);

        for (ImageView f : fruit) {
            toShow.getChildren().add(f);
        }
    }

    public void initSnake() {
        snake.clear();
        snake.add(new ImageView( new Image("SnakeHead20.jpg", true) ));
        snake.add(new ImageView( new Image("SnakeBody20.jpg", true) ));
        snake.add(new ImageView( new Image("SnakeBody20.jpg", true) ));
        snake.get(0).setX(640);
        snake.get(0).setY(600);
        snake.get(1).setX(640);
        snake.get(1).setY(620);
        snake.get(2).setX(640);
        snake.get(2).setY(640);
        for (ImageView s : snake) {
            toShow.getChildren().add(s);
        }
    }

    public void appendSnake() {
        for (ImageView s : snake) {
            toShow.getChildren().add(s);
        }
    }

    public void buildLevel(int toBuild) {
        toShow.getChildren().clear();

        System.out.println("auto lv 3");
        currLevel = toBuild;
        click.play();
        toShow.getChildren().clear();
        toShow.getChildren().add(base);
        toShow.getChildren().add(time);
        toShow.getChildren().add(lvl);
        toShow.getChildren().add(scoreNow);
        toShow.getChildren().add(high);

        if (toBuild == 1) {
            timeRemain = 30;
            finalLimit.set(limit * 3);
            lv1Fruit();
            lvl.setText("LEVEL: 1");
        }
        else if (toBuild == 2) {
            timeRemain = 30;
            finalLimit.set(limit * 2);
            lv2Fruit();
            lvl.setText("LEVEL: 2");
        }
        else {
            timeRemain = -30;
            finalLimit.set(limit);
            lv3Fruit();
            lvl.setText("LEVEL: 3");
        }
        if (isDead) {
            initSnake();
            isDead = false;
        }
        else {
            appendSnake();
        }
        if (!timer.isRunning()) {
            timer.start();
        }
        // stage.setScene(level1);
    }


    @Override
    public void start(Stage stage) {
        lvl.setText("LEVEL 1");
        lvl.setFont(new Font(30));
        lvl.setX(30);
        lvl.setY(60);

        time.setFont(new Font(30));
        time.setX(240);
        time.setY(60);
        score = 0;
        scoreNow.setText("SCORE: " + Integer.toString(score));
        scoreNow.setFont(new Font(30));
        scoreNow.setX(740);
        scoreNow.setY(60);

        high.setText("HIGHSCORE: " + Integer.toString(highScore));
        high.setFont(new Font(30));
        high.setX(1000);
        high.setY(60);


        stage.setTitle("Snake");
        Image menuBackground = new Image("MainMenu.gif", true);
        ImageView mainMenu = new ImageView(menuBackground);
        StackPane root = new StackPane(mainMenu);
        Scene menu = new Scene(root, 1280, 800);
        stage.setScene(menu);
        stage.setResizable(false);


        ImageView q = new ImageView( new Image("Quit.jpg", true) );
        Text yScore = new Text(Integer.toString(highScore));
        Text cScore = new Text(Integer.toString(score));
        yScore.setFont(new Font(80));
        yScore.setX(780);
        yScore.setY(430);
        cScore.setFont(new Font(80));
        cScore.setX(780);
        cScore.setY(510);
        Scene quit2 = new Scene(new Group(q, yScore, cScore), 1280, 800);

        timer = new AnimationTimerStatus() {
            long lastTicked = 0;
            long lastTimer = 0;
            @Override
            public void handle(long now) {
                if (lastTicked == 0) {
                    lastTicked = now;
                    handle_animation(dir.get(), currSpeed);
                    return;
                }
                if (now - lastTicked > finalLimit.get() / currSpeed) {
                    lastTicked = now;
                    handle_animation(dir.get(), currSpeed);
                    if (! timer.isRunning()) {
                        long startTime = System.currentTimeMillis();
                        while (System.currentTimeMillis() - startTime < 2000) {}
                        //System.out.println("Starting level 1");
                        //isDead = true;
                        //buildLevel(1);
                        if (score > highScore) {
                            highScore = score;
                            high.setText("HIGHSCORE: " + Integer.toString(highScore));
                        }
                        yScore.setText(Integer.toString(highScore));
                        cScore.setText(Integer.toString(score));
                        score = 0;
                        stage.setScene(quit2);
                        scoreNow.setText("SCORE: " + Integer.toString(score));
                        //timer.start();
                        dir.set(0);
                    }
                }
                if (timeRemain == 0) { // go to next level
                    if (currLevel == 1) {
                        System.out.println("auto lv 2");
                        buildLevel(2);
                        stage.setScene(level1);
                    }
                    else if (currLevel == 2) {
                        System.out.println("auto lv 3");
                        buildLevel(3);
                        stage.setScene(level1);
                    }
                }
                if (timeRemain > -30 && now - lastTimer >= 1000000000) {
                    lastTimer = now;
                    timeRemain--;
                    time.setText("TIME REMAINING: " + Integer.toString(timeRemain));
                }
                else if (timeRemain <= -30) {
                    time.setText("TIME REMAINING: UNLIMITED");
                }
            }
        };


        ImageView h = new ImageView( new Image("Help.jpg", true) );
        Scene help = new Scene(new Group(h), 1280, 800);


        Text paused = new Text(565, 25, "GAME PAUSED");
        paused.setFont(new Font(25));

        quit2.setOnKeyReleased(event -> {
            if (event.getCode() == KeyCode.Q) {
                System.out.println("quit");
                click2.play();
                stage.close();
            }
            if (event.getCode() == KeyCode.H) {
                System.out.println("quit");
                highScore = -1;
                stage.close();
            }
            if (event.getCode() == KeyCode.R) {
                System.out.println("quit");
                click2.play();
                stage.setScene(menu);
            }
        });

        help.setOnKeyReleased(event -> {
            if (event.getCode() == KeyCode.R) {
                System.out.println("reset");
                click2.play();
                timer.stop();
                toShow.getChildren().clear();
                stage.setScene(menu);
            }
            if (event.getCode() == KeyCode.Q) {
                System.out.println("quit");
                click2.play();
                cScore.setText(Integer.toString(score));
                yScore.setText(Integer.toString(highScore));
                stage.setScene(quit2);
            }
        });

        menu.setOnKeyReleased(event -> {
            if (event.getCode() == KeyCode.G) {
                System.out.println("Starting level 1");
                isDead = true;
                buildLevel(1);
                stage.setScene(level1);
                timer.start();
            }
            if (event.getCode() == KeyCode.H) {
                System.out.println("Display Help");
                click2.play();
                stage.setScene(help);
            }
            if (event.getCode() == KeyCode.R) {
                System.out.println("reset");
                click2.play();
                timer.stop();
                toShow.getChildren().clear();
                stage.setScene(menu);
            }
            if (event.getCode() == KeyCode.DIGIT1) {
                System.out.println("begin lv 1");
                isDead = true;
                buildLevel(1);
                stage.setScene(level1);
            }

            if (event.getCode() == KeyCode.DIGIT2) {
                System.out.println("begin lv 2");
                isDead = true;
                buildLevel(2);
                stage.setScene(level1);
            }
            if (event.getCode() == KeyCode.DIGIT3) {
                System.out.println("begin lv 3");
                isDead = true;
                buildLevel(3);
                stage.setScene(level1);
            }

            if (event.getCode() == KeyCode.Q) {
                System.out.println("quit");
                click2.play();
                if (score > highScore) {
                    highScore = score;
                    high.setText("HIGHSCORE: " + Integer.toString(highScore));
                }
                cScore.setText(Integer.toString(score));
                yScore.setText(Integer.toString(highScore));
                stage.setScene(quit2);
            }
        });

        level1.setOnKeyReleased(event -> {
            if (event.getCode() == KeyCode.Q) {
                timer.stop();
                System.out.println("quit");
                if (score > highScore) {
                    highScore = score;
                    high.setText("HIGHSCORE: " + Integer.toString(highScore));
                }
                cScore.setText(Integer.toString(score));
                yScore.setText(Integer.toString(highScore));
                click2.play();
                stage.setScene(quit2);
            }
            if (event.getCode() == KeyCode.P) {
                System.out.println("pause/unpause");
                click2.play();
                if (timer.isRunning()) {
                    timer.stop();
                    toShow.getChildren().add(paused);
                }
                else {
                    timer.start();
                    for (int i = 0; i < toShow.getChildren().size(); i++) {
                        if (toShow.getChildren().get(i).equals(paused)) {
                            toShow.getChildren().remove(i);
                            break;
                        }
                    }
                }
            }
            if (event.getCode() == KeyCode.RIGHT && timer.isRunning()) {
                System.out.println("turn right");
                dir.set((dir.get() + 1) % 4);
                snake.get(0).setRotate(snake.get(0).getRotate() + 90);
            }
            if (event.getCode() == KeyCode.LEFT && timer.isRunning()) {
                System.out.println("turn left");
                dir.set((dir.get() + 4 - 1) % 4);
                snake.get(0).setRotate(snake.get(0).getRotate() - 90);
            }

            if ((event.getCode() == KeyCode.W || event.getCode() == KeyCode.A || event.getCode() == KeyCode.S ||
                    event.getCode() == KeyCode.D) && timer.isRunning()) {
                System.out.println("zoom");
                if (event.getCode() == KeyCode.W) {
                    for (ImageView s : snake) {
                        s.setY(s.getY() - 80);
                    }
                } else if (event.getCode() == KeyCode.A) {
                    for (ImageView s : snake) {
                        s.setX(s.getX() - 80);
                    }
                } else if (event.getCode() == KeyCode.S) {
                    for (ImageView s : snake) {
                        s.setY(s.getY() + 80);
                    }
                } else {
                    for (ImageView s : snake) {
                        s.setX(s.getX() + 80);
                    }
                }

                //check collision with wall
                for (ImageView s : snake) {
                    if (s.getX() < 0 || s.getY() < 80 || s.getX() >= 1280 || s.getY() >= 800) {
                        System.out.println("Wall Collision");
                        gameOver.play();
                        timer.stop();
                        isDead = true;
                        if (score > highScore) {
                            highScore = score;
                            high.setText("HIGHSCORE: " + Integer.toString(highScore));
                        }
                        dir.set(0);
                        break;
                    }
                }
                // check fruit
                for (ImageView fr : fruit) {
                    if (snake.get(0).getX() == fr.getX() && snake.get(0).getY() == fr.getY()) {
                        System.out.println("Fruit capture");
                        fruitCapture.play();
                        boolean collide = false;
                        int x, y;
                        do {
                            collide = false;
                            x = 20 * (int) (Math.random()*(1260/20));
                            y = 80 + 20 * (int) (Math.random()*(700/20));

                            for (ImageView snakePart : snake) {
                                if (snakePart.getX() == x && snakePart.getY() == y) {
                                    collide = true;
                                    break;
                                }
                            }
                            for (ImageView f : fruit) {
                                if (collide && f.getX() == x && f.getY() == y) {
                                    collide = true;
                                    break;
                                }
                            }
                        } while (collide);

                        System.out.println("Moving fruit to (" + x + ", " + y + ")");
                        fr.setX(x);
                        fr.setY(y);

                        //grow snake
                        snake.add(new ImageView( new Image("SnakeBody20.jpg", true) ));
                        if (dir.get() == 0) {
                            snake.get(snake.size()-1).setX(snake.get(snake.size()-2).getX());
                            snake.get(snake.size()-1).setY(snake.get(snake.size()-2).getY()+20);
                        }
                        else if (dir.get() == 1) {
                            snake.get(snake.size()-1).setX(snake.get(snake.size()-2).getX()-20);
                            snake.get(snake.size()-1).setY(snake.get(snake.size()-2).getY());
                        }
                        else if (dir.get() == 2) {
                            snake.get(snake.size()-1).setX(snake.get(snake.size()-2).getX());
                            snake.get(snake.size()-1).setY(snake.get(snake.size()-2).getY()-20);
                        }
                        else if (dir.get() == 3) {
                            snake.get(snake.size()-1).setX(snake.get(snake.size()-2).getX()+20);
                            snake.get(snake.size()-1).setY(snake.get(snake.size()-2).getY());
                        }
                        toShow.getChildren().add(snake.get(snake.size()-1));
                        score++;
                        scoreNow.setText("SCORE: " + Integer.toString(score));
                    }
                }
            }

            if (event.getCode() == KeyCode.R) {
                System.out.println("reset");
                if (score > highScore) {
                    highScore = score;
                    high.setText("HIGHSCORE: " + Integer.toString(highScore));
                }
                dir.set(0);
                click2.play();
                timer.stop();
                toShow.getChildren().clear();
                stage.setScene(menu);
            }
            if (event.getCode() == KeyCode.DIGIT1) {
                buildLevel(1);
                stage.setScene(level1);
            }

            if (event.getCode() == KeyCode.DIGIT2) {
                buildLevel(2);
                stage.setScene(level1);
            }
            if (event.getCode() == KeyCode.DIGIT3) {
                buildLevel(3);
                stage.setScene(level1);
            }
        });

        stage.show();
    }

    void handle_animation(int direction, int speed) {
        // move snake bodies
        for (int i = snake.size() - 1; i > 0; i--) {
            snake.get(i).setX(snake.get(i-1).getX());
            snake.get(i).setY(snake.get(i-1).getY());
        }
        // move snake head
        if (direction == 0) { // up
            snake.get(0).setY(snake.get(0).getY() - speed);
        }
        else if (direction == 1) { // right
            snake.get(0).setX(snake.get(0).getX() + speed);
        }
        else if (direction == 2) { // down
            snake.get(0).setY(snake.get(0).getY() + speed);
        }
        else if (direction == 3) { // left
            snake.get(0).setX(snake.get(0).getX() - speed);
        }

        // run collision checks
        // collision fruit
        for (ImageView fr : fruit) {
            if (snake.get(0).getX() == fr.getX() && snake.get(0).getY() == fr.getY()) {
                System.out.println("Fruit capture");
                fruitCapture.play();
                boolean collide = false;
                int x, y;
                do {
                    collide = false;
                    x = 20 * (int) (Math.random()*(1260/20));
                    y = 80 + 20 * (int) (Math.random()*(700/20));

                    for (ImageView snakePart : snake) {
                        if (snakePart.getX() == x && snakePart.getY() == y) {
                            collide = true;
                            break;
                        }
                    }
                    for (ImageView f : fruit) {
                        if (collide && f.getX() == x && f.getY() == y) {
                            collide = true;
                            break;
                        }
                    }
                } while (collide);

                System.out.println("Moving fruit to (" + x + ", " + y + ")");
                fr.setX(x);
                fr.setY(y);

                //grow snake
                snake.add(new ImageView( new Image("SnakeBody20.jpg", true) ));
                if (direction == 0) {
                    snake.get(snake.size()-1).setX(snake.get(snake.size()-2).getX());
                    snake.get(snake.size()-1).setY(snake.get(snake.size()-2).getY()+20);
                }
                else if (direction == 1) {
                    snake.get(snake.size()-1).setX(snake.get(snake.size()-2).getX()-20);
                    snake.get(snake.size()-1).setY(snake.get(snake.size()-2).getY());
                }
                else if (direction == 2) {
                    snake.get(snake.size()-1).setX(snake.get(snake.size()-2).getX());
                    snake.get(snake.size()-1).setY(snake.get(snake.size()-2).getY()-20);
                }
                else if (direction == 3) {
                    snake.get(snake.size()-1).setX(snake.get(snake.size()-2).getX()+20);
                    snake.get(snake.size()-1).setY(snake.get(snake.size()-2).getY());
                }
                toShow.getChildren().add(snake.get(snake.size()-1));
                score++;
                scoreNow.setText("SCORE: " + Integer.toString(score));
            }
        }
        // collision wall
        if (snake.get(0).getX() < 0 || snake.get(0).getY() < 80 || snake.get(0).getX() >= 1280 || snake.get(0).getY() >= 800) {
            System.out.println("Wall Collision");
            gameOver.play();
            timer.stop();
            isDead = true;
            if (score > highScore) {
                highScore = score;
                high.setText("HIGHSCORE: " + Integer.toString(highScore));
            }
            dir.set(0);
            timeRemain = 30;
        }
        // collision self
        for (int i = 1; i < snake.size(); i++) {
            if (snake.get(i).getX() == snake.get(0).getX() && snake.get(i).getY() == snake.get(0).getY()) {
                System.out.println("Snake Collision");
                gameOver.play();
                timer.stop();
                isDead = true;
                if (score > highScore) {
                    highScore = score;
                    high.setText("HIGHSCORE: " + Integer.toString(highScore));
                }
                dir.set(0);
                timeRemain = 30;
                break;
            }
        }
    }

    public static void main(String[] args) {
        try {
            File f = new File("src//main//resources//highscore586415.txt");
            System.out.println(f.getAbsolutePath());
            Scanner scan = new Scanner(f);
            int h = scan.nextInt();
            highScore = h;
        } catch (Exception e) {System.out.println(e.toString());}
        launch();
    }

    @Override
    public void stop() throws Exception {
        super.stop();
        try {
            if (highScore > 0) {
                FileWriter k = new FileWriter("src//main//resources//highscore586415.txt");
                k.write(Integer.toString(highScore));
                k.close();
            }
            else {
                FileWriter k = new FileWriter("src//main//resources//highscore586415.txt");
                k.write(Integer.toString(0));
                k.close();
            }
        } catch (Exception e) {}
    }

}
