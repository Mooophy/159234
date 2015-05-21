package movie;

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
	
	private String title, director;
	private int time, quality;

}
