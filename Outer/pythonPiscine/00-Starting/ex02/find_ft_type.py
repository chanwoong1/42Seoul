def all_thing_is_obj(object: any) -> int:
    # your code here
    type = object.__class__.__name__
    if type == "list" or type == "tuple" or type == "set" or type == "dict":
        print(type[0].upper() + type[1:] + " :", object.__class__)
    elif type == "str":
        print(object, "is in the kitchen :", object.__class__)
    else:
        print("Type not found")
    return 42
