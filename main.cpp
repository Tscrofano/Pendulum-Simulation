#include <iostream>
#include <cmath>
#include <Eigen/Dense>
using namespace std;

class Pendulum
{
    private:
        double g = 9.8;
        double l = 1.0;

    public:

        Eigen::MatrixXd trajectory;

        double velocity_initial;
        double theta_initial;
        double t_max;
        double delta_t;

    Pendulum(double C_velocity_initial, double C_theta_initial, double C_t_max, double C_delta_t)
    {
        velocity_initial = C_velocity_initial;
        theta_initial    = C_theta_initial;
        t_max            = C_t_max;
        delta_t          = C_delta_t;
    }

    void simulate()
    {
        int n_steps = static_cast<int>(lround(t_max / delta_t)) + 1;

        trajectory.resize(n_steps, 2);

        trajectory(0, 0) = theta_initial;
        trajectory(0, 1) = velocity_initial;
        
        for (int i = 1; t <= t_max; t += delta_t, i++)
        {
            double theta_prev    = trajectory(i-1, 0);
            double velocity_prev = trajectory(i-1, 1);
            
            double velocity_new = velocity_prev - g/l * sin(theta_prev) * delta_t;
            double theta_new    = theta_prev + velocity_new * delta_t;

            trajectory(i, 0) = theta_new;
            trajectory(i, 1) = velocity_new;
        }
    }
    void printTraj() const
    {
        cout << trajectory << endl;
    }

};

int main()
{

    // Pendulum(double C_velocity_initial, double C_theta_initial (radians), double C_t_max, double C_delta_t)
    
    Pendulum results2(7, 2, 60, 0.25);
    results2.simulate();
    results2.printTraj();
    

    return 0;
}
