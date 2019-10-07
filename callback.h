#pragma once
#include <functional>
#include <vector>
#include <iostream>

namespace poke
{
using VoidCallback = std::function<void()>;

template <typename T>
class Callback
{
public:
	Callback() = default;

	/**
	 * \brief Add listener
	 * \param cb 
	 */
	void AddCallback(const T& cb)
	{
		callbacks_.push_back(cb); //TODO Ajouter un reserve au start pour que le push-back soit moins couteux
	}

	/**
	 * \brief Remove listener
	 * \param cb 
	 */
	void RemoveCallback(const T& cb)
	{
		//TODO supprimer un callback déjà implémenté. Il faudrait pour cela créer un index qui est retourné lors de la création. Ensuite il faudrait appler cette fonction avec cet index pour le supprimer directement.
	}

	/**
	 * \brief Send message to all listener
	 */
	void RegisterCallbacks() const
	{
		for (auto callback : callbacks_)
		{
			callback();
		}
	}

private:
	std::vector<T> callbacks_;
};
}
