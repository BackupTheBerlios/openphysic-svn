class GenData {

    private static double RPM(double t) { // vitesse calculee
	//return 0.0;
	return 8000;
    }

    private static double V(double t) { // vitesse mesuree (roue)
	//return 0.0;
	return 60.0;
    }

    private static double Ax(double t) { // acceleration laterale
	return 0.0;
    }

    private static double Ay(double t) { // acceleration longitudinale
	return 0.0;
    }    

    public static void main (String[] args){
	//System.out.println("Generating data");

	double delta_t = 0.1;
	double t = 0.0;
	final double t_max = 10.0;
	final String DATA_SEP = " "; //",";
	
	while( t < t_max ) {
	    t += delta_t;
	    System.out.println( t + DATA_SEP +
				RPM(t) + DATA_SEP +
				V(t) + DATA_SEP +
				Ax(t) + DATA_SEP +
				Ay(t) //+ DATA_SEP
			       );
	}

    }
    
}