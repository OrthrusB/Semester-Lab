class EcommerceStore:
    def __init__(self):
        self.products = [
            {'id': 1, 'name': 'Laptop', 'price': 1254.99},
            {'id': 2, 'name': 'Mouse', 'price': 75.50},
            {'id': 3, 'name': 'Keyboard', 'price': 125.00},
            {'id': 4, 'name': 'Headphones', 'price': 89.99}
        ]
        self.cart = []
        self.orders = []
    
    def add_to_cart(self, product_id, quantity=1):
        product = next((p for p in self.products if p['id'] == product_id), None)
        if product:
            self.cart.append({'product': product, 'quantity': quantity})
            print(f"✓ Added {quantity}x {product['name']}")
        else:
            print("✗ Product not found")
    
    def show_cart(self):
        if not self.cart:
            print("\n Cart is empty")
            return
        print("\n" + "="*50)
        print("CART")
        print("="*50)
        total = 0
        for item in self.cart:
            p = item['product']
            qty = item['quantity']
            subtotal = p['price'] * qty
            total += subtotal
            print(f"{p['name']} x{qty} - ${subtotal:.2f}")
        print(f"\nTotal: ${total:.2f}")
        print("="*50)
        return total
    
    def checkout(self):
        if not self.cart:
            print("Cart is empty!")
            return
        
        total = sum(item['product']['price'] * item['quantity'] for item in self.cart)
        order = {
            'order_id': len(self.orders) + 1,
            'items': self.cart.copy(),
            'total': total
        }
        self.orders.append(order)
        self.cart = []
        
        print("\n✓ ORDER PLACED SUCCESSFULLY!")
        print(f"Order ID: {order['order_id']}")
        print(f"Total: ${total:.2f}")
    
    def show_orders(self):
        if not self.orders:
            print("\nNo orders yet")
            return
        
        print("\n" + "="*50)
        print("ORDER HISTORY")
        print("="*50)
        for order in self.orders:
            print(f"\nOrder #{order['order_id']}")
            print("-"*50)
            for item in order['items']:
                p = item['product']
                qty = item['quantity']
                print(f"  • {p['name']} x{qty} - ${p['price'] * qty:.2f}")
            print(f"  Total: ${order['total']:.2f}")
        print("="*50)

# Demo
store = EcommerceStore()

store.add_to_cart(1, 1)  # Laptop
store.add_to_cart(2, 2)  # Mouse x2
store.add_to_cart(4, 1)  # Headphones

store.show_cart()
store.checkout()

store.add_to_cart(3, 1)  # Keyboard
store.checkout()

store.show_orders()