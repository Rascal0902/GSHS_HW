package com.hw;

import robocode.*;
import robocode.util.Utils;
import java.awt.Color;
import java.awt.geom.Point2D;
import java.util.Random;

public class InterfaceBot extends AdvancedRobot {

	Random rand = new Random();
	private AdvancedEnemyBot enemy = new AdvancedEnemyBot();
	
	private RobotPart[] parts = new RobotPart[3];
	
	private final static int RADAR = 0;
	private final static int GUN = 1;
	private final static int TANK = 2;
	
	public void run() {
		parts[RADAR] = new Radar();
		parts[GUN] = new Gun();
		parts[TANK] = new Tank();
		
		for (int i = 0; i < parts.length; i++) {
			parts[i].init();
		}
		
		for (int i = 0; true; i = (i + 1) % parts.length) {
			parts[i].move();
			if (i== 0) {
				execute();
			}
		}
	}
	
	public interface RobotPart {
		public void init();
		public void move();
	}
	
	public class Radar implements RobotPart {

		@Override
		public void init() {
			// TODO Auto-generated method stub
			System.out.println("Radar Init");
			setAdjustRadarForGunTurn(true);
			
		}

		@Override
		public void move() {
			// TODO Auto-generated method stub
			//System.out.println("Radar Move");
			if (getOthers() < 3 ) {
				double angleToEnemy = getHeadingRadians() + Math.toRadians(enemy.getBearing());
				double radarTurn = Utils.normalRelativeAngle(angleToEnemy - getRadarHeadingRadians());
				double extraTurn = Math.min(Math.atan(36.0/enemy.getDistance()), Rules.RADAR_TURN_RATE_RADIANS);
				radarTurn += (radarTurn < 0 ? -extraTurn : extraTurn);
				setTurnRadarRightRadians(radarTurn);
			} else {
				setTurnRadarRightRadians(100000);
				if (!enemy.none()) {
					double absoluteBearing = getHeadingRadians() + Math.toRadians(enemy.getBearing());
					if (enemy.getEnergy() < 20) {
						setTurnRadarRightRadians(
	                            3.5 * Utils.normalRelativeAngle( absoluteBearing
	                                - getRadarHeadingRadians() ) );
					}
				}
			}
			
		}
		
		public boolean shouldTrack(ScannedRobotEvent e) {
			// TODO
			return ( enemy.none() || e.getDistance() < enemy.getDistance() - 100
								  || e.getName().equals( enemy.getName() ) );
		}
		
		public boolean wasTracking(RobotDeathEvent e) {
			return e.getName().equals(enemy.getName());
		}
	}
	
	
	public class Gun implements RobotPart {

		@Override
		public void init() {
			// TODO Auto-generated method stub
			System.out.println("Gun Init");
			setAdjustGunForRobotTurn(true);
			
		}

		@Override
		public void move() {
			// TODO Auto-generated method stub
			//System.out.println("Gun Move");
			if (enemy.none()) {
				return;
			}
			if (getOthers() < 3) {
				if (enemy.getDistance() > 20) {
					double firePower = Math.min(500/enemy.getDistance(), 3);
					double bulletSpeed = 20 - firePower * 3;
					long time = (long)(enemy.getDistance() / bulletSpeed);
					double futureX = enemy.getFutureX(time) - 5;
					double futureY = enemy.getFutureY(time) + 5;
					double absDeg = absoluteBearing(getX(), getY(), futureX, futureY);
					
					setTurnGunRight(normalizeBearing(absDeg - getGunHeading()));
					
					if (getGunHeat() == 0 && Math.abs(getGunTurnRemaining()) < 10) {
						setFire(firePower);
					}
				} else {
					double absDeg = absoluteBearing(getX(), getY(), enemy.getX(), enemy.getY());
					setTurnGunRight(normalizeBearing(absDeg - getGunHeading()));
					setFire(10);

				}
			} else { //
                double firePower = Math.min( 50 / enemy.getDistance(), 3 );
                double bulletSpeed = 20 - firePower * 3;
                long time = (long)( enemy.getDistance() / bulletSpeed );

                double futureX = enemy.getFutureX( time ) - 5;
                double futureY = enemy.getFutureY( time ) + 5;
                double absDeg = absoluteBearing( getX(), getY(), futureX, futureY );
                setTurnGunRight(normalizeBearing(absDeg - getGunHeading()));
                if (getGunHeat() == 0 && Math.abs( getGunTurnRemaining()) < 10) {
                    setFire( firePower );
                }
			}
			
		}
	}
	
	public class Tank implements RobotPart {
		private byte moveDirection = 1;

		@Override
		public void init() {
			// TODO Auto-generated method stub
			System.out.println("Tank Init");
			setColors( Color.black, Color.black, Color.red, Color.black, Color.black );
			
		}

		@Override
		public void move() {
			// TODO Auto-generated method stub
			//System.out.println("Tank Move");
			if (getVelocity() == 0) {
				setMaxVelocity(8);
				moveDirection *= -1;
			}
			if (getTime() % 50 == 0 ) {
                setColors( Color.black, Color.black, Color.red, Color.black,
                    Color.black );
            }
            else if (getTime() % 50 == 25 ) {
                setColors( Color.blue, Color.red, Color.white, Color.red,
                    Color.red );
            }
			
			if (getOthers() < 3) {
				if (enemy.getDistance() < 20) {
					setTurnRight(normalizeBearing(enemy.getBearing()) + 180 + (rand.nextInt(20)-20));
					setAhead(rand.nextInt(40));
				}
				
				if (enemy.getDistance() < 60) {
                    setTurnRight( getHeading() * moveDirection );
                    setTurnRight( normalizeBearing( enemy.getBearing() + 90
                        - ( 15 * moveDirection ) ) );
                    setAhead( enemy.getDistance() * moveDirection );
				} else {
                    setTurnRight( normalizeBearing(enemy.getBearing() + 90 ) );
                    
                    if (((getX() < getBattleFieldWidth() - 20) || getX() > 20 )
                        && (getY() < getBattleFieldHeight() - 20 ) || getY() > 20 ) {
                        setTurnRight( normalizeBearing(enemy.getBearing() + 110));
                        setAhead(1000 * moveDirection);
                    } else {
                        setTurnRight( getHeading() * moveDirection + rand.nextInt( 90 ) );
                        setAhead( 200 * moveDirection );
                    }
				}
			} else {
				final int wallMargin = 200;
                if (getTime() % 20 == 0) {
                    moveDirection *= -1;
                }
                if (!(getX() < wallMargin || getX() > getBattleFieldWidth()
                                - wallMargin || getY() < wallMargin
                    || getY() > getBattleFieldHeight() - wallMargin )) {
                    setAhead(enemy.getDistance()*moveDirection);
                }
                if (getX() < 50 || getX() > getBattleFieldWidth()
                                - 50 || getY() < 50
                    || getY() > getBattleFieldHeight() - 50 ) {
                    setTurnRight(normalizeBearing(enemy.getBearing() + 15));
                }
                if ( enemy.getEnergy() > 75 ) {
                    setTurnRight( normalizeBearing(enemy.getBearing() - 180));
                }

                if ( enemy.getDistance() < 50 ) {
                    setTurnRight( normalizeBearing( enemy.getBearing() + 90 ) );
                    setAhead(enemy.getDistance() * moveDirection);
                }
                setAhead(enemy.getDistance() * moveDirection);
			}
		}
	}
	
	public void onScannedRobot(ScannedRobotEvent e) {
		Radar radar = (Radar)parts[RADAR];
		if (radar.shouldTrack(e)) {
			enemy.update(e, this);
		}
	}
	public void onRobotDeath(RobotDeathEvent e) {
		Radar radar = (Radar)parts[RADAR];
		if (radar.wasTracking(e)) {
			enemy.reset();
		}
	}
	public double absoluteBearing( double x1, double y1, double x2, double y2 ) {
        double xo = x2 - x1;
        double yo = y2 - y1;
        double hyp = Point2D.distance( x1, y1, x2, y2 );
        double arcSin = Math.toDegrees( Math.asin( xo / hyp ) );
        double bearing = 0;

        if ( xo > 0 && yo > 0 ) { 
            bearing = arcSin;
        }
        else if ( xo < 0 && yo > 0 ) { 
            bearing = 360 + arcSin; 
        }
        else if ( xo > 0 && yo < 0 ) {
            bearing = 180 - arcSin;
        }
        else if ( xo < 0 && yo < 0 ) {
            bearing = 180 - arcSin; 
        }
        return bearing;
    }
	public double normalizeBearing( double angle ) {
        while ( angle > 180 ) {
            angle -= 360;
        }
        while ( angle < -180 ) {
            angle += 360;
        }
        return angle;
    }
}