def NULL_not_found(object: any) -> int:
    # your code here
    object_class_name = object.__class__.__name__
    if object_class_name == "NoneType" and object is None:
        print("Nothing :", object, object.__class__)
    elif object_class_name == "float" and object != object:
        print("Cheese :", object, object.__class__)
    elif object_class_name == "int" and object == 0:
        print("Zero :", object, object.__class__)
    elif object_class_name == "str" and object == "":
        print("Empty :", object, object.__class__)
    elif object_class_name == "bool" and object is False:
        print("Fake :", object, object.__class__)
    else:
        print("Type not found")
        return 1
    return 0
