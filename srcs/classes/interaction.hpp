//
// Created by Gilberto Dougal on 4/24/21.
//

#ifndef HELLO_SFML_INTERACTION_HPP
#define HELLO_SFML_INTERACTION_HPP
#include "canonball_t.hpp"


class interaction {
private:

public:
	interaction() = default;
	interaction(const interaction &ref) = default;
	interaction &operator=(const interaction &ref) = default;
	virtual ~interaction() = default;

	template<class T, class T1>
	static const bool	co_orientation(T& object1, T1& object2) {
		float	length_btwn_centre	= lenght(object1.getPosition(), object2.getPosition());
		float	length_in_move			= lenght(object1.getPosition() + object1.getDirections(), object2.getPosition() + object2.getDirections());
		return (length_btwn_centre >= length_in_move);
	}

	template<class T, class T1>
	static const bool	is_collapse(T& object1, T1& object2) {
		float	length_btwn_centre	= lenght(object1.getPosition(), object2.getPosition());
		float	sum_radius					= object1.getRadius() + object2.getRadius();
		return (length_btwn_centre <= sum_radius);
	}

	static void	collapse_targets(I_target*& target1, I_target*& target2) {
		if (&target1 == &target2)
			return;
		else if(co_orientation(*target1, *target2) && is_collapse(*target1, *target2)) {
				I_target::swap_directions(target1, target2);
		}
	};

	static bool	collapse_target_with_ball(I_target*& target, cannonball_t& ball) {
		if(is_collapse(*target, ball)) {
			target->minus_hp();
			if (target->getHp()) {
				vector2f	new_direction(target->getDirections().x * -1, target->getDirections().y * -1);
				target->setDirections(new_direction);
			}
			return true;
		}
		return false;
	};
};


#endif //HELLO_SFML_INTERACTION_HPP
