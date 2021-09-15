# Design pattern

## 1. SOLID
### 1.1 Single Responsibility Principle
### 1.2 Open-Close Principle
### 1.3 Liskov Subsitution Principle
### 1.4 Interface Segregation Principle
### 1.5 Dependency Inversion Principle
> - High-level modules should not depend on low-level modules. Both should depend on abstractions.
> - Abstractions should not depend on details. Details should depend on abstractions.

## 2. Creational Design Pattern
**Target** : 
> - Deal with the creation(construction) of objects
> - Explicit(Constructor) vs implicit (DI, reflection, etc.)
> - Wholesale (single statement) vs piewise (step-by-step).

### 2.1 Builder
- **Builder**: When construction get a little bit too complicated.
- **Brief**: Builder is a creational design pattern that lets you construct complex objects step by step. The pattern allows you to produce different types and representations of an object using the same construction code.
- **Motivation**:
> - Some object are simple and can be created in a single constructor call.
> - Other objects require a lot of ceremony to create.
> - Having an object with 10 constructor arguments is not productive.
> - Instead, opt for piewise construction.
> - **Builder** provide api to construct object step-by-step.

### 2.2 Factoreis
- **Factoreis**: Factory method & Abstract factory.
- **Brief**: A component is responsible solely for the wholesale (not piecewise) creation of objects.
  - ***Factory method*** is a creational design pattern that provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created.
  - ***Abstract Factory*** is a creational design pattern that lets you produce families of related objects without specifying their concrete classes.
- **Motivation:**
> - Object creation logic becomes too convoluted.
> - Constructor is not descriptive.
>   - Name mandated by name of containing type.
>   - Can not overload with same set of arguments with different names.
>   - Can turn into "optional parameter hell".
> - Object creation(non-piecewise, like Builder) can be outsource to 
>   - A separate function (Factory Method)
>   - That may exist in a separate class (Factory)
>   - Can create hierarchy of factories with Abstract Factory.

### 2.3 Prototype
- **Prototype**: When it's easier to copy an existing object to fully initialize a new one.
- **Brief**: Prototype is a creational design pattern that lets you copy existing objects without making your code dependent on their classes.
- **Motivation:**
> - Complicated objects(eg., cars, airplane...) aren't design from scratch.
>   - They are reiterate existing designs.
> - An existing(partially or fully constructed) design is a prototype.
> - We make a copy(clone) the prototype and customize it.
>   - Requires "deep copy" support.
> - We make the cloning convient (eg via a Factory). 

### 2.4 Singleton
- **Singleton**: A design pattern everyone loves to hate... but it is really that bad.
- **Brief**: Singleton is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access point to this instance.
- **Motivation:**
> - For some components it only makes sense to have one in the system.
>   - Database repository.
>   - Object factory.
> - The constructor call is expensive
>   - We only do it once.
>   - We provide everyone with the same instance.
> - Want to prevent anyone creating additional copies.
> - Need to take care of lazy instantiation and thread-safety.

## 2. Structural Design Pattern
**Target**:
> - 

### 2.1 Adapter
- **Adapter**: Getting the interface you want from the interface you have.
- **Brief**: Adapter is a structural design pattern that allows objects with incompatible interfaces to collaborate.
- **Example:**
> - Electrical devices have different power(interface) requirements.
>   - Voltage (110V, 220V...)
>   - Socket/plug type (EUROPE, UK, USA).
> - We can not modify our gadget to support every possible interface.
>   - Some support voltage level (220V/110V)
> - Thus, we are using a special device (and Adapter) to give us the interface we require from the interface we have.

### 2.2 Bridge
- **Bridge**: Connecting components together from abstraction.
- **Brief**: Bridge is a structural design pattern that lets you split a large class or a set of closely related classes into two separate hierarchies—abstraction and implementation—which can be developed independently of each other.
- **Motivation:**
> - Bridge prevents a 'Cartesian product' complexity explosion. For example
>   - Base class ThreadScheduler
>   - Can be Preemptive or Non-Preemptive (Cooperative).
>   - Can run on Windows, Unix.
>   - End up with a 2x2 scenario: WindowPTS, UnixPTS, WindowsCTS, UnixCTS.
> - Bridge pattern avoids the entity explosion.

### 2.3 Composite
- **Composite**: Treating individual and aggregate objects uniformly.
- **Brief**: Composite is a structural design pattern that lets you compose objects into tree structures and then work with these structures as if they were individual objects.
- **Motivation:**
> - Objects use the other objects' fields/properties/members through inheritance and composition.
> - Composition lets us make the compound objects. 
> - Composition design pattern is used to treat both single and composite object uniformly.

### 2.4 Decorator
- **Decorator**: Adding behavior without altering the class itself
- **Brief**: Decorator is a structural design pattern that lets you attach new behaviors to objects by placing these objects inside special wrapper objects that contain the behaviors.
- **Motivation:**
> - Want to argument an object with additional functionality.
> - Do not want to rewrite or alter existing code (violate OCP).
> - Want to keep new functionality in separate (conform SRP).
> - Need to able to interact with existing structures.
> - Two options:
>   - Aggregate the decorated object
>   - Inherit from the decorated object.

### 2.5 Facade
- **Facade**: Expose several components through a single interface.
- **Brief**: Facade is a structural design pattern that provides a simplified interface to a library, a framework, or any other complex set of classes.
- **Motivation:**
> - Balancing the complexity and presentation usability.
> - Example Typical home.
>   - Many subsystem (electrial, sanitation).
>   - Complex internal structure (floor layer).
>   - End user is not exposed to internal 
> - Same with the software.
>   - Many systems working to provide flexibility, but ...
>   - API consumers want it to 'just work'. 

### 2.6 Flyweight
- **Flyweight**: Space optimization!.
- **Brief**: Flyweight is a structural design pattern that lets you fit more objects into the available amount of RAM by sharing common parts of state between multiple objects instead of keeping all of the data in each object.
- **Motivation:**
> - Avoid redundancy when storing data.
> - For example : Bold and Italic text in console.
>   - Don't want to each character have a formatting character.
>   - Operate on range(eg: line number, start/end positions).

### 2.Proxy
- **Proxy**: An interface for accessing particular resource.
- **Brief**: Proxy is a structural design pattern that lets you provide a substitute or placeholder for another object. A proxy controls access to the original object, allowing you to perform something either before or after the request gets through to the original object.
- **Motivation:**
> - You are calling foo.
> - This assumes that the *foo* is in same process as the *bar()*
> - What if, latter on you want to put all Foo-related operations into separate process.
>   - Can you changing your code?
> - Proxy come to play!!!
>   - Same interface, entirely different behavior.
> - This is called communication proxy.
>   - Other types: logging, virtual, guarding, ...

## 3. Behavioral Design Pattern
**Target**:
> - They are all different; no central theme.

### 3.1 Chain of Responsibility
- **Chain of Responsibility**: Sequence of handlers processing an event one after another.
- **Brief**: Chain of Responsibility is a behavioral design pattern that lets you pass requests along a chain of handlers. Upon receiving a request, each handler decides either to process the request or to pass it to the next handler in the chain.
- **Motivation:**
> - Unethical behavior by an employee; who takes the blame?
>   - Employee
>   - Manager
>   - CEO
> - You click a graphical element on a form.
>   - Button handles it, stops further processing.
>   - Underlying group box.
>   - Underlying window.
> - CCG compunter game.
>   - Creature has attack & defense value.
>   - Those can be boosted by other cards.

### 3.2 Command
- **Command**: You shall not pass.
- **Brief**: Command is a behavioral design pattern that turns a request into a stand-alone object that contains all information about the request. This transformation lets you pass requests as a method arguments, delay or queue a request’s execution, and support undoable operations.
- **Motivation:**
> - Ordinary C++ statements are perishable
>   - Can not undo a field/property assignment.
>   - Can not directly serialize a sequence of actions(calls)
> - Want an object that represents an operation.
>   - X should change its field Y to the value Z.
>   - X should do W()
> - Uses: GUI commands, multi-level undo/redo macro recording and more.

### 3.3 Iterator
- **Chain of Responsibility**: 
- **Brief**: Iterator is a behavioral design pattern that lets you traverse elements of a collection without exposing its underlying representation (list, stack, tree, etc.).
- **Motivation:**
> - 
> 
### 3.4 Mediator
- **Chain of Responsibility**: 
- **Brief**: Mediator is a behavioral design pattern that lets you reduce chaotic dependencies between objects. The pattern restricts direct communications between the objects and forces them to collaborate only via a mediator object.
- **Motivation:**
> - 
> 
### 3.5 Memento
- **Chain of Responsibility**: 
- **Brief**: Memento is a behavioral design pattern that lets you save and restore the previous state of an object without revealing the details of its implementation.
- **Motivation:**
> - 
> 
### 3.6 Observer
- **Chain of Responsibility**: 
- **Brief**: Observer is a behavioral design pattern that lets you define a subscription mechanism to notify multiple objects about any events that happen to the object they’re observing.
- **Motivation:**
> - 
> 
### 3.7 State
- **Chain of Responsibility**: 
- **Brief**: State is a behavioral design pattern that lets an object alter its behavior when its internal state changes. It appears as if the object changed its class.
- **Motivation:**
> - 
> 
### 3.8 Strategy
- **Chain of Responsibility**: 
- **Brief**: Strategy is a behavioral design pattern that lets you define a family of algorithms, put each of them into a separate class, and make their objects interchangeable.
- **Motivation:**
> - 
> 
### 3.9 Template method
- **Chain of Responsibility**: 
- **Brief**: Template Method is a behavioral design pattern that defines the skeleton of an algorithm in the superclass but lets subclasses override specific steps of the algorithm without changing its structure.
- **Motivation:**
> - 
> 
### 3.10 Visitor
- **Chain of Responsibility**: 
- **Brief**: Visitor is a behavioral design pattern that lets you separate algorithms from the objects on which they operate.
- **Motivation:**
> - 


## Note to build on Cygwin.
- To build on windows with cygwin does following command
```shell
    cmake -S . -B build -G "Unix Makefiles"             # to create build directory and '-S .' mean to specify CMakeLists.txt folder.
```