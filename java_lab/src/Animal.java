class Animal {
    void sound() {
        System.out.println("Animal makes sound");
    }

    static void display(Animal a) {
        a.sound();
    }

    public static void main(String[] args) {
        Animal a = new Animal();
        Dog d = new Dog();
        Cat c = new Cat();
        Cow cow = new Cow();

        display(a);
        display(d);
        display(c);
        display(cow);
    }
}

class Dog extends Animal {
    void sound() {
        System.out.println("Dog barks");
    }
}

class Cat extends Animal {
    void sound() {
        System.out.println("Cat meows");
    }
}

class Cow extends Animal {
    void sound() {
        System.out.println("Cow moos");
    }
}
