# pybind11 make_key_iterator race condition

To reproduce:
```bash
uv venv -p 3.14t
source .venv/bin/activate
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

or another error but this is the most common one I've got.
As a workaround, you can force the iterator type to be created at module load time.
```bash
git apply patch.patch
uv pip install .
pytest --parallel-threads=6 tests
```
