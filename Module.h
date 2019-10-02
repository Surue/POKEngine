#ifndef MODULE_H
#define MODULE_H

namespace poke
{
class Module
{
public:
	Module();
	~Module();

	/**
	 * \brief Initialize the core module. Call only once
	 */
	virtual void Init() = 0;
	/**
	 * \brief Update the module every frame
	 */
	virtual void Update() = 0;
	/**
	 * \brief physical update the module every frame
	 */
	virtual void PhysicUpdate() = 0;
	/**
	 * \brief Render the module
	 */
	virtual void Render() = 0;
	/**
	 * \brief destroy the module
	 */
	virtual void Destroy() = 0;

	void Test();

private:
};
}
#endif //MODULE_H