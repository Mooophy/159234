package movie;

import java.io.*;

public class Revised extends Movie
{
    public void setRevisedTime(int rt){ this.revised_time = rt; }
    public void setChanges(String c){ this.changes = c; }
    @Override
    public void display()
    {
        super.display();
        System.out.println( "Revised time: " + revised_time + "\nChanges: " + changes );
    }

    public void getData(String filename)
    {
        super.getData(filename);
        BufferedReader buffer = null;
        try
        {
            buffer = new BufferedReader(new FileReader(filename));
        }
        catch (FileNotFoundException e)
        {
            System.out.println(e.getMessage());
        }
    }

    private int revised_time;
    private String changes;
}
