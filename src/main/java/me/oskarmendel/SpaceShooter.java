package me.oskarmendel;

import me.oskarmendel.core.Game;

/**
 * 
 * @author Oskar Mendel
 *
 */
public class SpaceShooter {
    public static void main( String[] args ) {
        (new Thread(new Game())).start();
    }
}
