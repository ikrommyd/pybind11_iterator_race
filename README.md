# pybind11 make_key_iterator race condition

To reproduce:
```bash
uv venv -p 3.14t
uv pip install .
pytest --parallel-threads=6 tests
```

should get you

```
    def test_iterator():
        c = Container()
>       assert set(c) == {"key1", "key2", "key3"}
               ^^^^^^
E       TypeError: Object of type 'iterator' is not an instance of 'iterator'
```
