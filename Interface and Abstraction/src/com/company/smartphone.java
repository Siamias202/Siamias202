package com.company;

abstract class printing
{
    abstract void print();
}

abstract  class showing
{
    abstract void show();
}



public class smartphone extends phone implements iCamera,iInternet,iMusicPlayer
{

    @Override
    public void click() {
        System.out.println("Clicking");
    }

    @Override
    public void record() {
        System.out.println("Recording");
    }

    @Override
    public void internet() {
        System.out.println("Browsing");
    }

    @Override
    public void play() {
        System.out.println("Playing Music");
    }

    @Override
    public void stop() {
        System.out.println("Stopping");
    }
}
