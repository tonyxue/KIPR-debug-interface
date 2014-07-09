#include <stdio.h>
int main()
{
	int m1=0,m2=3,pageno=0;
	double createDriveTime;
	printf("Start!\n");
	extra_buttons_show();
	while (1)
	{
		while (pageno == 0)
		{
			set_a_button_text("Forward");
			set_b_button_text("Backward");
			set_c_button_text("All Off");
			set_x_button_text("OpenHand");
			set_y_button_text("CloseHand");
			set_z_button_text("Create Page");
			
			if (a_button_clicked())
			{
				printf("Moving forward...\n");
				motor(m1,100);
				motor(m2,100);
				while (!c_button_clicked())
				{
					msleep(1);
				}
				ao();
			}
			if (b_button_clicked())
			{
				printf("Moving backward...\n");
				motor(m1,-100);
				motor(m2,-100);
				while (!c_button_clicked())
				{
					msleep(1);
				}
				ao();
			}
			if (x_button_clicked())
			{
				enable_servo(3);
				set_servo_position(3,0);
				msleep(300);
				disable_servo(3);
			}
			if (y_button_clicked())
			{
				enable_servo(3);
				set_servo_position(3,1300);
				msleep(300);
				disable_servo(3);
			}
			if (z_button_clicked())
			{
				pageno=1;
				create_connect();
			}
		}

		while (pageno == 1)
		{
			set_a_button_text("Create Fwd");
			set_b_button_text("Create Bwd");
			set_c_button_text("Stop");
			set_x_button_text("Turn R");
			set_y_button_text("Turn L");
			set_z_button_text("M S Page");
			
			if (a_button_clicked())
			{
				createDriveTime = 0;
				printf("Create Moving forward w/ spd 100...\n");
				create_drive_straight(100);
				createDriveTime = seconds();
				while (!c_button_clicked())
				{
					msleep(1);
				}
				create_stop();
				printf("Time: %f seconds\n",seconds() - createDriveTime );
			}
			if (b_button_clicked())
			{
				createDriveTime = 0;
				printf("Create Moving backward w/ spd 100...\n");
				create_drive_straight(-100);
				createDriveTime = seconds();
				while (!c_button_clicked())
				{
					msleep(1);
				}
				create_stop();
				printf("Time: %f seconds\n",seconds() - createDriveTime );
			}
			if (x_button_clicked())
			{
				create_drive(-50,0);
				while (!c_button_clicked())
				{
					msleep(1);
				}
				create_stop();
			}
			if (y_button_clicked())
			{
				create_drive(50,0);
				while (!c_button_clicked())
				{
					msleep(1);
				}
				create_stop();
			}
			if (z_button_clicked())
			{
				pageno=0;
				create_disconnect();
			}
		}
	}
	
	return 0;
}
