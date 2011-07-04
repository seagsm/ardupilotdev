/* ThermoPilot 1.0 Header file : June 14, 2011 */
//
// SUCESSFULLY TESTED IN FLIGHT ON EASYGLIDER on June 14, 2011 by Jean-Louis Naudin
//
// Updated version by JL Naudin - June 13, 2011 
// added GSBOOST variable to increase Ground_Speed in windy conditions
// added CLOSED_LOOP_NAV to do closed the loop navigation
/*

These Flight Modes can be changed either here or directly in events.pde
	
	MANUAL			= Full manual control via the mux - cannot be overridden
	SARSEC			= Run a SAR sector type pattern
	AUTO			= What you bought the thing for
	RTL				= Come home - Home is set at first good GPS read from ground startup
    HEADALT                 = Lock the current heading and altitude
*/

// Debug options - set only one of these options to 1 at a time, set the others to 0
#define DEBUG_SUBSYSTEM 0   		                        // 0 = no debug
								// 1 = Debug the Radio input
								// 2 = Debug the Servo output
								// 3 = Debug the Sensor input
								// 4 = Debug the GPS input
								// 5 = Debug the GPS input - RAW HEX OUTPUT
								// 6 = Debug the IMU
								// 7 = Debug the Control Switch
								// 8 = Debug the Throttle
								// 9 = Radio Min Max values

#define POSITION_1   MANUAL     // the default, don't bother changing.
#define POSITION_2   HEADALT    // HEADALT Heading + Altitude old up to MAX_DIST then RTL
//#define POSITION_2   SARSEC   // Run a SAR sector type pattern
#define POSITION_3   RTL        // Return To Launch
#define POSITION_4   SARSEC     // AUTO Run the Flight Plan

// So why isn't AUTO here by default? Well, please try and run Stabilize first, 
// then FLY_BY_WIRE_A to verify you have good gains set up correctly 
// before you try Auto and wreck your plane. I'll sleep better that way...


/***************************************/
//HARDWARE CONFIGURATION
#define SHIELD_VERSION 	1		// Old (red) shield versions is 0, the new (blue) shield version is 1, -1 = no shield
#define AIRSPEED_SENSOR 0 		// (boolean) Do you have an airspeed sensor attached? 1= yes, 0 = no.

#define GPS_PROTOCOL 	6		// 0 = NMEA
					// 1 = SIRF, 
					// 2 = uBlox
					// 3 = ArduIMU
					// 4 = MediaTek MTK16, 
                                        // 6 = GPS simulator
					// -1 = no GPS
//0-4 Ground Control Station:
#define GCS_PROTOCOL 	0		// 0 = Standard ArduPilot (LabVIEW/HappyKillmore), 
					// -1 = no GCS (no telemtry output)

/***************************************/
//Thermopile sensors:
#define ENABLE_Z_SENSOR 0  		// 0 = no Z sensor, 1 = use Z sensor (no Z requires field calibration with each flight)
#define XY_SENSOR_LOCATION 0 	        // XY Thermopiles Sensor placement
					// Mounted right side up:	0 = cable in front, 1 = cable behind
					// Mounted upside down: 	2 = cable in front, 3 = cable behind
#define PITCH_TRIM 0			// deg * 100 : allows you to offset bad IR sensor placement
#define ROLL_TRIM 0			// deg * 100 : allows you to offset bad IR sensor placement
#define AOA 0				// deg * 100 : the angle your plane flies at level - use the IMU to find this value.
#define ALT_EST_GAIN .01		// the gain of the altitude estimation function, lower number = slower error correction and smoother output

/***************************************/
//Battery:
#define BATTERY_EVENT 0 	        // (boolean) 0 = don't read battery, 1 = read battery voltage (only if you have it wired up!)
#define INPUT_VOLTAGE 5200.0 	        // (Millivolts) voltage your power regulator is feeding your ArduPilot to have an accurate pressure and battery level readings. (you need a multimeter to measure and set this of course)

/***************************************/
// RADIO
//3-1
#define THROTTLE_PIN 11			// pin 13, or pin 11 only (13 was old default, 11 is a better choice for most people)
#define THROTTLE_OUT 1			// For debugging - 0 = no throttle, 1 = normal throttle
#define THROTTLE_FAILSAFE 0 	        // Do you want to react to a throttle failsafe condition? Default is no 0, Yes is 1
#define THROTTLE_FS_VALUE 1111	        // (microseconds) What value to trigger failsafe 
#define REVERSE_THROTTLE 0		// 0 = Normal mode. 1 = Reverse mode - Try and reverse throttle direction on your radio first, most ESC use low values for low throttle.
#define FAILSAFE_ACTION 2		// 1 = come home in AUTO, LOITER,	2 = dont come home
#define AUTO_TRIM 1			// 0 = no, 1 = set the trim of the radio when switching from Manual
#define SET_RADIO_LIMITS 0		// 0 = no, 1 = set the limits of the Channels with the radio at launch each time; see manual for more
#define RADIO_TYPE 0 			// 0 = sequential PWM pulses, 1 = simultaneous PWM pulses
// 
// CH1: 1029|1861   CH2: 1039|1866   CH3: 1057|1620   CH4: 1049|1886    // Turnigy 9X
// CH1: 1094|2055   CH2: 1154|1901   CH3: 1555|2400   CH4: 1500|1500    // MX16s

// 
#define CH1_MIN 1094 			// (Microseconds) Range of Ailerons/ Rudder
#define CH1_MAX 2055 			// (Microseconds)
#define CH2_MIN 1154 			// (Microseconds) Range of Elevator
#define CH2_MAX 1901 			// (Microseconds)
#define CH3_MIN 1057 			// (Microseconds) Range of Throttle  - 1000 to 2000 ONLY!!!
#define CH3_MAX 1620 			// (Microseconds)
#define CH4_MIN 1049 			// (Microseconds) Range of Rudder
#define CH4_MAX 1886 			// (Microseconds)

#define ADVERSE_ROLL 1		        // adverse roll correction based on Aileron input 
#define CH4_RUDDER 0			// 1 = Use CH4 for rudder, 0 = use CH4 for something else - like an egg drop.

#define PAYLOAD_CLOSED 45		// -45 to 45 degrees max
#define PAYLOAD_OPEN -45		// -45 to 45 degrees max

/***************************************/
// AIRFRAME SETTINGS
#define MIXING_MODE 0			//Servo mixing mode 0 = Normal, 1 = Elevons (or v tail)

// NOTE - IF USING ELEVONS, 1-2 AND 1-3 SHOULD BE 1
#define REVERSE_ROLL -1			// To reverse roll, PUT -1 to reverse it
#define REVERSE_PITCH -1		// To reverse pitch, PUT -1 to reverse it
#define REVERSE_RUDDER -1		// To reverse rudder for 4 channel control setups

// JUST FOR ELEVONS:
#define REVERSE_ELEVONS 1    	// Use 1 for regular, -1 if you need to reverse roll direction
#define REVERSE_CH1_ELEVON -1 	// To reverse channel 1 elevon servo, PUT -1 to reverse it
#define REVERSE_CH2_ELEVON 1 	// To reverse channel 2 elevon servo, PUT -1 to reverse it

/***************************************/
// Airplane speed control
#define AIRSPEED_CRUISE 16		// meters/s : Speed to try and maintain - You must set this value even without an airspeed sensor!
#define AIRSPEED_RATIO 0.1254	        // If your airspeed is under-reporting, increase this value to something like .2
#define GSBOOST  60                     // boost the throttle if ground speed is too low in case of windy conditions

// NOTE - The range for throttle values is 0 to 125
// NOTE - For proper tuning the THROTTLE_CRUISE value should be the correct value to produce AIRSPEED_CRUISE in straight and level flight with your airframe
#define THROTTLE_MIN 0			// (0-100) raise it if your plane falls to quickly when decending.
#define THROTTLE_CRUISE 45    	        // (0-100) Default throttle value - Used for central value.
#define THROTTLE_MAX 70   	        // (0-100) example: 70 = 56% throttle (lower this if your plane is overpowered)  // 80

// For use in Fly By Wire B mode in meters per second
#define AIRSPEED_FBW_MIN 6		// meters/s : Minimum airspeed for Fly By Wire mode B, throttle stick at bottom
#define AIRSPEED_FBW_MAX 30		// meters/s : Maximum airspeed for Fly By Wire mode B, throttle stick at top

/***************************************/
//NAVIGATION: PARAMETERS
//Note: Some Gains are now variables
//4-1
#define HEAD_MAX 4000                   // deg * 100 : The maximum commanded bank angle (left and right) 	degrees*100
#define PITCH_MAX 1500			// deg * 100 : The maximum commanded pitch up angle 	degrees*100
#define PITCH_MIN -2000                 // deg * 100 : The maximum commanded pitch down angle 	degrees*100
#define LOITER_RADIUS 40 		// meters : radius in meters of a Loiter
#define REMEMBER_LAST_WAYPOINT 1 	// If set 1 = will remember the last waypoint even if you restart the autopilot.
					// 0 = Will start from WP 1 (not 0) every time you switch into AUTO mode. 
#define CLOSED_LOOP_NAV 1               // set=1 if closed loop navigation else 0 (Return To Lauch)

#define MAX_DIST       300              // max distance (in m) for the HEADALT mode
#define SARSEC_BRANCH  300              // Long branch of the SARSEC pattern

/***************************************/
// Auto launch and land
//	If you are using ArduIMU the minimum recommended TAKE_OFF_PITCH is 30 degrees due to linear acceleration effects on the IMU
//  If your airframe cannot climb out at 30 degrees do not use this feature if using ArduIMU
#define USE_AUTO_LAUNCH 0		// If set to 1 then in AUTO mode roll will be held to zero and pitch to TAKE_OFF_PITCH until TAKE_OFF_ALT is reached
#define TAKE_OFF_ALT 75			// meters.  Altitude below which take-off controls apply
#define TAKE_OFF_PITCH 15		// degrees : Pitch value to hold during take-off

//	This section is for setting up auto landings
//	You must have your airframe tuned well and plan your flight carefully to successfully execute auto landing
#define USE_AUTO_LAND 0		// If set to 1 then in AUTO mode roll will be held to zero and pitch to TAKE_OFF_PITCH until TAKE_OFF_ALT is reached
#define LAND_PITCH 15		// degrees : Pitch value to hold during landing
#define AIRSPEED_SLOW 5		// meters/s 
#define THROTTLE_SLOW 20    	// 0-100 : This should be the throttle value that produces AIRSPEED_SLOW in straight and level flight

#define SLOW_RADIUS 60		// meters : When this becomes the current waypoint we will decrease airspeed_cruise to AIRSPEED_SLOW. Replace 999 with the beginning of your landing pattern 
#define THROTTLE_CUT_RADIUS 40	// meters : When this becomes the current waypoint we will cut the throttle; set it so it is well beyond the touchdown zone so that it is not reached, else you will enter RTL mode or loop waypoints
				    			


