# Argument parsing in command line apps

## Python has rich library called argparse to do this

## The Namespace object

**class argparse.Namespace**

Simple class used by default by parse_args() to create an object holding attributes and return it.

This class is deliberately simple, just an object subclass with a readable string representation. If you prefer to have dict-like view of the attributes, you can use the standard Python idiom, vars():

``` python 
>>> parser = argparse.ArgumentParser()
>>> parser.add_argument('--foo')
>>> args = parser.parse_args(['--foo', 'BAR'])
>>> vars(args)
{'foo': 'BAR'}
```
It may also be useful to have an ArgumentParser assign attributes to an already existing object, rather than a new Namespace object. This can be achieved by specifying the namespace= keyword argument:

``` python
>>> class C:
...     pass
...
>>> c = C()
>>> parser = argparse.ArgumentParser()
>>> parser.add_argument('--foo')
>>> parser.parse_args(args=['--foo', 'BAR'], namespace=c)
>>> c.foo
'BAR'
```