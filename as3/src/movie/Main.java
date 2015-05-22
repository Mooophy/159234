package movie;

public class Main
{

    /**
     * @param args
     */
    public static void main(String[] args)
    {
        movie.Movie m = new movie.Movie();
        m.setTitle("Go Go Go!!");
        m.setDirector("Someone");
        m.setQuality(4);

        System.out.print(m.toString());
    }

}