class GenData {

    private double RPM(double t) {
	return 0.0;
    }

    private double V(double t) {
	return 0.0;
    }

    private double Ax(double t) {
	return 0.0;
    }

    private double Ay(double t) {
	return 0.0;
    }    

    public static void main (String[] args){
	//System.out.println("Generating data");

	double delta_t = 0.1;
	double t = 0;
	
	while( t < 10 ) {
	    t += delta_t;
	    System.out.println(t);
	}

    }
    
}