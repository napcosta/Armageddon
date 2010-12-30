// This file is part of CGLib.
//
// CGLib is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// CGLib is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CGLib; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
// Copyright 2007 Carlos Martinho

#ifndef LOCKABLE_ORDERED_MAP_H
#define LOCKABLE_ORDERED_MAP_H

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "CommandQueue.h"

namespace cg {

	template <class T>
	class LockableOrderedMap {

	private:
		std::map<const std::string,T*> _names;
		typedef typename std::map<const std::string,T*>::iterator tNameIterator;

		std::vector<T*> _elements;
		typedef typename std::vector<T*>::iterator tElementIterator;

		bool _isLocked;
		CommandQueue<T> _commandQueue;

	public:
		LockableOrderedMap();
		~LockableOrderedMap();

		typedef typename std::vector<T*>::iterator iterator;
		tElementIterator begin();
		tElementIterator end();

		unsigned int size() const;
		bool exists(const std::string& id);
		T* get(const std::string& id);
		void add(std::string id, T* element);
		void remove(const std::string& id);
		void removeAll();
		void destroy(const std::string& id);
		void destroyAll();

		void lock();
		void unlock();
	};

    template<class T>
    LockableOrderedMap<T>::LockableOrderedMap() {
		_isLocked = false;
    }
    template<class T>
    LockableOrderedMap<T>::~LockableOrderedMap() {
		_isLocked = false;
		removeAll();
    }
    template<class T>
    typename LockableOrderedMap<T>::iterator LockableOrderedMap<T>::begin() {
		return _elements.begin();
	}
    template<class T>
    typename LockableOrderedMap<T>::iterator LockableOrderedMap<T>::end() {
		return _elements.end();
	}
	template<class T>
    unsigned int LockableOrderedMap<T>::size() const{
		return (unsigned int)_names.size();
    }
    template<class T>
    bool LockableOrderedMap<T>::exists(const std::string& id) {
		if(_names.count(id) == 0) {
			return _commandQueue.existsElement(id);
		} else {
			return true;
		}
    }
	template <class T>
	T* LockableOrderedMap<T>::get(const std::string& id) {
		tNameIterator i = _names.find(id);
		if(i == _names.end()) {
			return _commandQueue.getElement(id);
		} else {
			return i->second;
		}
	}
	template <class T>
	void LockableOrderedMap<T>::add(std::string id, T* element) {
		if(_isLocked) {
			_commandQueue.add(new AddCommand<T>(id,element));
			_commandQueue.addElement(id,element);
		} else {
			std::pair<tNameIterator,bool> result = _names.insert(std::make_pair(id, element));
			if(result.second == false) {
				throw std::runtime_error("[cg::ActivityMap] element '" + id + "' already exists.");
			}
			_elements.push_back(element);
		}
	}
	template <class T>
	void LockableOrderedMap<T>::remove(const std::string& id) {
		if(_isLocked) {
			_commandQueue.add(new RemoveCommand<T>(id));
		} else {
			tNameIterator i = _names.find(id);
			if(i != _names.end()) {
				tElementIterator j = find(_elements.begin(), _elements.end(), i->second);
				_elements.erase(j);
				_names.erase(id);
			}
		}
	}
	template <class T>
	void LockableOrderedMap<T>::removeAll() {
		if(_isLocked) {
			_commandQueue.add(new RemoveAllCommand<T>());
		} else {
			_elements.clear();
			_names.clear();
		}
	}
	template <class T>
	void LockableOrderedMap<T>::destroy(const std::string& id) {
		if(_isLocked) {
			_commandQueue.add(new DestroyCommand<T>(id));
		} else {
			tNameIterator i = _names.find(id);
			if(i != _names.end()) {
				tElementIterator j = find(_elements.begin(), _elements.end(), i->second);
				delete (*j);
				_elements.erase(j);
				_names.erase(id);
			}
		}
	}
	template <class T>
	void LockableOrderedMap<T>::destroyAll() {
		if(_isLocked) {
			_commandQueue.add(new DestroyAllCommand<T>());
		} else {
			for (tElementIterator i = _elements.begin(); i != _elements.end(); i++) {
				delete (*i);
			}
			_elements.clear();
			_names.clear();
		}
	}
	template <class T>
	void LockableOrderedMap<T>::lock() {
		_isLocked = true;
	}
	template <class T>
	void LockableOrderedMap<T>::unlock() {
		_isLocked = false;
		_commandQueue.execute(this);
	}
}

#endif // LOCKABLE_ORDERED_MAP_H
