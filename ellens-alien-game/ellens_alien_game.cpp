namespace targets
{
    class Alien
    {
    public:
        Alien(int x, int y) : x_coordinate(x), y_coordinate(y), health(3) {}

        int get_health()
        {
            return health;
        }

        bool hit()
        {
            if (health > 0)
            {
                health--;
            }

            return true;
        }

        bool is_alive()
        {
            return health > 0;
        }

        bool teleport(int x_new, int y_new)
        {
            x_coordinate = x_new;
            y_coordinate = y_new;

            return true;
        }

        bool collision_detection(Alien another_alien)
        {
            return another_alien.x_coordinate == x_coordinate &&
                   another_alien.y_coordinate == y_coordinate;
        }

        int health = 3;
        int x_coordinate;
        int y_coordinate;
    };

} // namespace targets
