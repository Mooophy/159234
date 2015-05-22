package movie;

import java.io.*;

public class Movie
{
    public void setTitle(String t){ this.title = t; }
    public void setDirctor(String d){ this.director = d; }
    public void setQuality(int q){ this.quality = q; }

    @Override
    public String toString()
    {
        return "\nTitle: " + this.title + "\nDirector: " + this.director + "\nTime: " + this.time + " mins\nQuality: " + "*****".substring(0, this.quality);
    }
    
    public void display(){ System.out.println(this.toString()); }


    public void getData(String filename)
    {
        BufferedReader buffer = null;

        try
        {
            buffer = new BufferedReader(new FileReader(filename));
        }
        catch (FileNotFoundException e)
        {
            System.out.println(e.getMessage());
        }

        try
        {
            this.title = buffer.readLine();
            this.director = buffer.readLine();
            this.time = Integer.parseInt(buffer.readLine());
            this.quality = Integer.parseInt(buffer.readLine());
        }
        catch (IOException e)
        {
            System.out.println(e.getMessage());
        }
    }

    private String title, director;
    private int time, quality;
}