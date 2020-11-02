#pragma once
// Класс для работы с данными
class Worker
{
public:
	// Получение информации
	virtual void Load() = 0;
	// Сохранение информации
	virtual void Save() = 0;
};	

