#pragma once

namespace poke
{
struct ModuleContainer;

class Module
{
public:
	Module();
	virtual ~Module() = default;

	//Make sure that a module cannot be modified from outside the module container
	Module(Module&) = delete;
	Module(Module&&) = delete;
	Module& operator =(Module);
	Module& operator =(Module&&) noexcept;

	/**
	* \brief Initialize the core module. Call only once
	*/
	virtual void Init(){}
	/**
	* \brief Update the module every frame
	*/
	virtual void Update(){}
	/**
	* \brief physical update the module every frame
	*/
	virtual void PhysicUpdate(){}
	/**
	* \brief Render the module
	*/
	virtual void Render(){}
	/**
	* \brief destroy the module
	*/
	virtual void Destroy(){}
};
}
