#include "Group.h"

namespace cg {

	Group::Group(const std::string& id) : Entity(id) {
	}
	Group::~Group() {
		_entities.unlock();
		_entities.destroyAll();
	}
	unsigned int Group::size() {
		return _entities.size();
	}
	bool Group::exists(const std::string& id) {
		return _entities.exists(id);
	}
	Entity* Group::get(const std::string& id) {
		return _entities.get(id);
	}
	void Group::add(Entity* entity) {
		std::string id = entity->getId();
		_entities.add(id,entity);
	}
	void Group::remove(const std::string& id) {
		_entities.remove(id);
	}
	void Group::removeAll() {
		_entities.removeAll();
	}
	void Group::destroy(const std::string& id) {
		_entities.destroy(id);
	}
	void Group::destroyAll() {
		_entities.destroyAll();
	}
	void Group::init() {
		preInit();
		createEntities();
		for(tEntityIterator i = _entities.begin(); i != _entities.end(); i++) {
			(*i)->init();
		}
		postInit();
	}
	void Group::dump(std::ofstream& file) {
		file << state << " " << _id << " [Group of " << size() << "]";
		for(tEntityIterator i = _entities.begin(); i != _entities.end(); i++) {
			file << std::endl;
			file << "    ";
			(*i)->dump(file);
		}
	}
	LockableOrderedMap<Entity>* Group::getEntities() {
		return &_entities;
	}
	LockableOrderedMap<Entity>::iterator Group::begin() {
		return _entities.begin();
	}
	LockableOrderedMap<Entity>::iterator Group::end() {
		return _entities.end();
	}
}
