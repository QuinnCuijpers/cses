#include <iostream>
#include <cmath>

typedef long long ll;

ll length_from_square_location(ll x,
                               ll y,
                               ll square_location_x, ll square_location_y)
{
    ll x_dist;
    ll y_dist;
    if (x >= square_location_x)
    {
        x_dist = x - square_location_x;
    }
    else
    {
        x_dist = square_location_x - x;
    }

    if (y >= square_location_y)
    {
        y_dist = y - square_location_y;
    }
    else
    {
        y_dist = square_location_y - y;
    }

    return x_dist + y_dist;
}

int main()
{
    int t;
    ll x, y;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        std::cin >> y >> x;

        // reindex to 0 based
        x -= 1LL;
        y -= 1LL;

        ll ring_index = (long long)std::max(x, y);

        ll square_value = (ring_index + 1LL) * (ring_index + 1LL);

        bool parity = ring_index % 2LL == 0LL;

        // even indexed ring
        if (parity)
        {
            ll square_location_x = ring_index;
            ll square_location_y = 0;
            std::cout << square_value -
                             length_from_square_location(x,
                                                         y,
                                                         square_location_x,
                                                         square_location_y)
                      << std::endl;
        }
        else
        {
            ll square_location_x = 0;
            ll square_location_y = ring_index;
            std::cout << square_value -
                             length_from_square_location(x,
                                                         y,
                                                         square_location_x,
                                                         square_location_y)
                      << std::endl;
        }
    }
}