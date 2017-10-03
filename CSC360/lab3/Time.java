/*
 * Author: To embarrassed to say.
 *
 * A very basic Time class with hours between 0 and 23
 * and minutes between 0 and 59.
 */
public class Time {

	private int hours;
	private int minutes;

	/*
	 * Create a new time object that is set to hh:mm.
	 */
	public Time(int hours, int minutes) {
		setHours(hours);
		setMinutes(minutes);
	}

	/*
	 * Create a new time object that is set to 00:00.
	 */
	public Time() {
		this(0,0);
	}

	/*
	 * Set the hours of this time.
	 */
	public void setHours(int hours) {
		// check the validity of the incoming value.
		if (hours >= 0 && hours < 24) {
			this.hours = hours;
		}
		// else do nothing.
	}

	/*
	 * Return the hours of this time.
 	 */
	public int getHours() {
		return hours;
	}

	/*
	 * Set the minutes of this time.
	 */
	public void setMinutes(int minutes) {
		if (minutes >= 0 && minutes < 60) {
			this.minutes = minutes;
		}
	}

	/*
	 * Return the minutes of this time.
	 */
	public int getMinutes() {
		 return minutes;
	}

	/*
	 * Returns true if this time is equal to the other time.
	 */
	public boolean equals(Time other) {
		return (this.hours == other.hours && this.minutes == other.minutes);
	}

	/*
	 * Returns a formatted string of this time.
	 */
	public String toString() {
		StringBuilder s = new StringBuilder(11);
		s.append("Time: ");
		if (this.hours < 10) {
			s.append("0"+this.hours);
		} else {
			s.append(hours);
		}
		s.append(':');
		if (minutes < 10) {
			s.append("0"+minutes);
		} else {
			s.append(minutes);
		}
		return s.toString();
	}

	/* 
	 * Compares this time to an other time.
	 * If this time comes before the other time, then return a number less than 0.
	 * If this time is the same as the other time, then return 0
	 * If this time comes after the other time, then return a number greater than 0.
	 */
	public int compareTo(Time other) {
		int hourDiff = this.hours - other.hours;
		if (this.hours - other.hours == 0) {
			return this.minutes - other.minutes;
		} else {
			return this.hours - other.hours;
		}
	}

	/* 
	 * Add some time to this time.
	 */
	public void add(Time other) {
		int sumHours = this.hours + other.hours;
		int sumMins = this.minutes+other.minutes;
		if (sumMins > 60) {
			sumHours++;
		}
		this.minutes = sumMins%60;
		this.hours = sumHours%24;
	}

	/* unit tester*/
	public static void main(String[] args) {
		// test the default constructor
		Time t1 = new Time();
		// print the results:
		System.out.println("Created a default time object: "+t1);
		// Create a proper time
		Time t2 = new Time(11,12);
		System.out.println("Created a proper time object: "+t2);
		// Create a bad time
		Time t3 = new Time(24,-3);
		System.out.println("Created a time with incorrect parameters: "+t3);
		// Test the compare and equals
		Time t4 = new Time(13,49);
		System.out.println("Created a new time: "+t4);
		if (!t2.equals(t4)) {
			System.out.println(t2+" is not the same as "+t4);
		} else {
			System.out.println("Error in the equals method.");
		}
		if (t2.compareTo(t4) < 0) {
			System.out.println(t2+" comes before "+t4);
		} else {
			System.out.println("Error in the compareTo method.");
		}
		System.out.print("After adding "+t4+" to "+t2+", we get ");
		t2.add(t4);
		System.out.println(t2);
	}
}
