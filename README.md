# Proyecto Quest

## Niveles

El proyecto está separado en 2 niveles:

- `L_Quests_Blueprints`
- `L_Quests_CPP`

Por defecto, el motor abre el nivel `L_Quests_Blueprints`.

---

## L_Quests_Blueprints

En este nivel se encuentran **monedas, diamantes y 2 estructuras negras**.

Con **E** se interactúa con estas estructuras mediante un **Line Trace**, y cada una otorga una misión. La misión se muestra en el panel ubicado a la izquierda de la pantalla.

Las dos misiones son de recolección y requieren recolectar **5 objetos**.

> **Nota:** Si los objetos se recolectan antes de comenzar la misión, es necesario reiniciar el nivel, ya que no se programó un respawn.

---

## L_Quests_CPP

Este nivel se encuentra en la carpeta `Levels/`.

En él también se encuentran las monedas y los diamantes, pero no se pueden recolectar, ya que su overlap utiliza el componente de la versión Blueprint.

La **estructura cónica** otorga la Quest de la versión C++, que consiste en recolectar **5 cubos**.

Los Widgets funcionan de la misma forma que en la versión Blueprint, pero utilizan los **datos, estructuras y componentes creados para la implementación en C++**.
