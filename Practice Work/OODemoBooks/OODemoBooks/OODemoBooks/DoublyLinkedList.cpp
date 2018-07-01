//template <typename T>
//void double_linked<T>::push_back(T data)
//{
//    tail = new node(data, tail, NULL);
//46.    if( tail->prev )
//47.        tail->prev->next = tail;
//48.
//49.    if( empty() )
//50.        head = tail;
//51.}
//52.
//53.template <typename T>
//54.void double_linked<T>::push_front(T data)
//55.{
//56.    head = new node(data, NULL, head);
//57.    if( head->next )
//58.        head->next->prev = head;
//59.
//60.    if( empty() )
//61.        tail = head;
//62.}
//63.
//64.template<typename T>
//65.T double_linked<T>::pop_back()
//66.{
//67.    if( empty() )
//68.        throw("double_linked : list empty");
//69.    node* temp(tail);
//70.    T data( tail->data );
//71.    tail = tail->prev ;
//72.
//73.    if( tail )
//74.        tail->next = NULL;
//75.    else
//76.        head = NULL ;
//77.
//78.    delete temp;
//79.    return data;
//80.}
//81.
//82.template<typename T>
//83.T double_linked<T>::pop_front()
//84.{
//85.    if( empty() )
//86.        throw("double_linked : list empty");
//87.    node* temp(head);
//88.    T data( head->data );
//89.    head = head->next ;
//90.
//91.    if( head )
//92.        head->prev = NULL;
//93.    else
//94.        tail = NULL;
//95.
//96.    delete temp;
//97.    return data;
//98.}
