from typing import Union, Any

class ListNode(object):
    def __init__(self, data: Union[int, None]):
        """
        Initializes the node instance.

        Parameters
        ----------
        data : Union[int, None]
            An integer representing the data associated with the node instance
        """
        self.data: Union[int, None] = data
        self.next: Any = None
        self.prev: Any = None
        
    def __repr__(self) -> str:
        """
        Return a meaningful printable string describing the node instance.

        Returns
        -------
        str
            A description of the node instance
        """
        class_name = type(self).__name__
        return f"{class_name}(data = {self.data})"
