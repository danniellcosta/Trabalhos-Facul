using UnityEngine;

public class Halter : MonoBehaviour
{
    public int pontos = 10;


    protected virtual void Comer()
    {
        FindObjectOfType<GameManager>().HalterConsumido(this);
    }
    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.gameObject.layer == LayerMask.NameToLayer("Muscleman"))
        {
            Comer();
        }
    }
}
